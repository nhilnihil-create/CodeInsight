#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;


ll num[30];
int main(){
    int n;
    string s;
    cin>>n>>s;

    rep(i,n){
        num[s[i]-'a']++;
    }

    ll res=1;
    rep(i,26){
        res*=num[i]+1;
        res%=MOD;
    }

    res-=1;
    if(res<0) res+=MOD;

    cout<<res<<endl;
}