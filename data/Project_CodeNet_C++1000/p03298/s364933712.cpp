#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
map<pair<string,string>,ll> mp1,mp2;
void dfs(int k,string s,string r,string b,int l){
    if(k==s.size()){
        if(l==0){
            mp1[make_pair(r,b)]++;
        }
        else{
            mp2[make_pair(r,b)]++;
        }
        return;
    }
    dfs(k+1,s,r+s[k],b,l);
    dfs(k+1,s,r,b+s[k],l);

}
int main()
{
    int n;cin>>n;
    string s;cin>>s;
    string vo,s1,s2;
    s1=s.substr(0,n);
    s2=s.substr(n,n);
    reverse(all(s2));
    dfs(0,s1,vo,vo,0);
    dfs(0,s2,vo,vo,1);
    ll ans=0;
    for(auto p:mp1){
        ans+=p.second*mp2[p.first];
    }
    cout<<ans<<endl;
}