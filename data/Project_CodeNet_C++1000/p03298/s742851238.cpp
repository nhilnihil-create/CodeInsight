#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<string,string> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    string s;cin>>s;
    string pre=s.substr(0,n),suf=s.substr(n,n);
    reverse(suf.begin(),suf.end());
    map<string,ll> mp;
    for(int i=0;i<(1<<n);i++){
        string red="",blu="";
        int st=i;
        for(int j=0;j<n;j++){
            if(st%2) red+=suf[j];
            else blu+=suf[j];

            st/=2;
        }
        mp[red+"$"+blu]++;
    }
    ll res=0;
    for(int i=0;i<(1<<n);i++){
        string red="",blu="";
        int st=i;
        for(int j=0;j<n;j++){
            if(st%2) red+=pre[j];
            else blu+=pre[j];

            st/=2;
        }
        res += mp[red+"$"+blu];
    }
    cout<<res<<endl;
}
