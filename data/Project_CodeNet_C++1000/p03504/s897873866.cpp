#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, c;
    cin>>n>>c;
    vector<vector<pair<int, int> > > v(c);
    rep(i, n){
        int s, t, ch;
        cin>>s>>t>>ch;
        --ch;
        v[ch].push_back(make_pair(s, t));
    }
    map<int, int> mp;
    rep(ch, c){
        map<int, int> now;
        rep(i, v[ch].size()){
            int s = v[ch][i].first;
            int t = v[ch][i].second;
            for(int j = s;j<=t;j++){
                now[j] = 1;
            }
        }
        for(auto p : now){
            mp[p.first]+=p.second;
        }
    }
    int ans = 0;
    for(auto p : mp){
        ans = max(ans, p.second);
    }
    cout<<ans<<endl;
    return 0;
}