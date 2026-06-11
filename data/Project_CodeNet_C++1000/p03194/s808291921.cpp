#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

vector<bool> prime;
map<long,long> mp;

void sieve(long max){
    prime.resize(sqrt(max)+1,true);
    prime[0]=false;
    prime[1]=false;
    for(long i=2; i*i<=sqrt(max); ++i) // 0からsqrt(max)まで調べる
        if(prime[i]==true){ // iが素数ならば
            for(long j=2; i*j<=sqrt(max); ++j){ // (max以下の)iの倍数は
                prime[i*j] = false;// 素数ではない
            }
        }
}
int main(){
    long n,p;
    cin >> n >> p;
    long ans = 1;
    sieve(p);
    for(long i=2;i<prime.size();i++){
        mp[i]=0;
        long x=p;
        if(prime[i]==true){
            for(long j=0;pow(i,j)<p;j++){
                if(x%i==0){
                    mp[i]++;
                    x/=i;
                }else break;
            }
            if(mp[i]>=n && mp[i]/n>1){
                ans=ans*pow(i,mp[i]/n);
            }else if(mp[i]>=n){
                ans=ans*i;
            }
        }
    }
    if(n==1)ans=p;
    cout << ans;
}