#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define cw(x) cout << (x) << endl
#define cww(x,y) cout << (x) << ' ' << y << endl
#define cwa(x) for(auto a:x) cout << a << ' ';cout << endl
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_set<int> usi;
typedef vector<pi> vpi;

int i;
string s,k="keyence";

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    for(cin >> s;i<8;i++){
        if(s.substr(0,i) == k.substr(0,i))
            if(i==7 || s.substr(s.length()-7+i,-1)==k.substr(i,-1))
                return cw("YES"), 0;
    }
    cw("NO");

    return 0;
}
