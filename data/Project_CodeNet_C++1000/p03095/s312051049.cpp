#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    string S; cin>>S;

    map<char,int> mp;
    for(auto c:S) mp[c]++;

    int64_t ans=1;
    for(auto m:mp){
        ans*=m.second+1;
        ans%=MOD;
    }
    ans--;

    cout<<ans<<endl;
}