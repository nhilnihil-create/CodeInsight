#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n;cin >> n;
    vector<int> num;
    vector<bool> isPrime(55556,true);
    for(int i=2;i*i<=55556;i++){
        if(isPrime[i]){
            for(int j=2*i;j<=55556;j+=i){
                isPrime[j]=false;
            }
        }
    }
    int cnt=0;
    for(int i=2;i<=55556;i++){
        if(isPrime[i]&&i%5==1){
            if(cnt==n) continue;
            num.push_back(i);
            cnt++;
        }
    }
    for(int i=0;i<num.size();i++) cout << num[i] << " ";
    cout << endl;
    return 0;
}