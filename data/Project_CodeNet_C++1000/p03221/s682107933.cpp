#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, M, tmp=0;
map<ll, pair<ll, ll>> MP;
map<ll, ll> MP1;
vector<string> ans;
signed main(){
    cin >> N >> M;
    ans.resize(M);
    for(int i=0;i<M;i++) {
        ll p, y;
        cin >> p >> y;
        MP[y] = make_pair(p, i);
    }
    for(map<ll, pair<ll, ll>>::iterator itr=MP.begin();itr!=MP.end();itr++) {
        pair<ll, pair<ll, ll>> pp = *itr;
        MP1[pp.second.first]++;
        string s1 = to_string(pp.second.first);
        while(s1.size()<6) {
            s1 = "0"+s1;
        }
        string s2 = to_string(MP1[pp.second.first]);
        while(s2.size()<6) {
            s2 = "0"+s2;
        }
        ans[pp.second.second] = s1+s2;
    }
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << endl;
    }
    return 0;
}