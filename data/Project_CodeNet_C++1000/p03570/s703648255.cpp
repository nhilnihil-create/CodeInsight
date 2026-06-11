///In the name of God
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define y1 def1
#define X first
#define Y second
#define endl '\n'
#define all(o) o.begin(), o.end()
#define IOS ios::sync_with_stdio(0), cin.tie(0)
map<int,int> mp;
main(){
    string s;
    cin >> s;
    int cur = 0;
    mp[0] = 0;
    for(int i=0; i<s.size(); i++){
        cur ^= ((1LL)<<(s[i]-'a'));
        int mn = 1e9;
        for(int j=-1; j<26; j++){
            int ne = cur;
            if(j >= 0) ne = cur ^ ((1LL)<<j);
            if(mp.count(ne))
                mn = min(mn, mp[ne] + 1);
        }
        if(i == s.size() - 1)
            cout << mn << endl;
        if(mp.count(cur))
            mp[cur] = min(mp[cur], mn);
        else
            mp[cur] = mn;
    }
}
