#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
//head

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;

    set<string> ans;

    for(int i = 0; i + t.size() - 1 < s.size(); i++) {
        bool ok = true;
        for(int j = 0; j < t.size(); j++) {
            if(!(s[i+j] == t[j] || s[i+j] == '?')) ok = false;
        }
        if(ok) {
            string pos = s;
            for(int j = 0; j < t.size(); j++) {
                pos[i + j] = t[j];
            }
            for(int j = 0; j < pos.size(); j++) if(pos[j] == '?') pos[j] = 'a';
            ans.insert(pos);
        }
    }
    if(ans.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << *(ans.begin()) << endl;
    }
    return 0;
}
