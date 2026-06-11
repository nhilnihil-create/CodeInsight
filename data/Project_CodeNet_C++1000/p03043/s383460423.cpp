#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N,K;cin>>N>>K;
    int score=0;
    double ans=0;
    int counter=0;
    for(int i=1;i<=N;i++){
        counter=0;
        score=i;
        if(score>=K){
            ans+=1;
            continue;
        }
        while(1){
            counter++;
            score*=2;
            if(score>=K){
                ans+=1.0/pow(2,counter);
                break;
            }
        }
    }
    printf("%1.12f\n",ans/N);
}