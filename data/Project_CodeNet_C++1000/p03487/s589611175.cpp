#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;

    map<int,int> m;
    rep(i,n){
        int a;
        cin>>a;
        m[a]++;
    }

    int ans=0;
    for(auto e : m){
        if(e.second>=e.first) ans+=e.second-e.first;
        else ans+=e.second;
    }

    cout<<ans<<endl;
}