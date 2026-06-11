#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin>>a;
        mp[a]++;
    }
    int ans=0;
    for(auto p:mp){
        if(p.first<=p.second){
            ans+=p.second-p.first;
        }
        else{
            ans+=p.second;
        }
    }
    cout<<ans<<endl;
    return 0;
}