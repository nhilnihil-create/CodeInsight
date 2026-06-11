#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;cin>>test;while(test--)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_output(v) for(auto it=v.begin();it!=v.end();it++){if(it!=v.begin())cout<<" ";cout<<*it;}cout<<endl;
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;

int main(){
    map<int,ll> map;
    set<int> set;
    int n;
    cin>>n;
    int x;
    rep(i,n){
        cin>>x;
        if(map.count(x)){
            map[x]++;
        }else{
            set.insert(x);
            map[x]=1;
        }
    }
    ll ans=0;
    for(auto value:set){
        if(map[value]>=value){
            ans+=map[value]-value;
        }else{
            ans+=map[value];
        }
    }
    cout<<ans<<endl;
}