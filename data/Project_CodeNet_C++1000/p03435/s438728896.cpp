#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unordered_set<int> usi;
typedef vector<pi> vpi;

#define cw(x) cout << (x) << endl
#define cww(x,y) cout << (x) << ' ' << y << endl
#define cwa(x) for(auto a:x) cout << a << ' ';cout << endl
#define all(v) (v).begin(),(v).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)

int b[3],a[3],i,j;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    F0R(i,3) cin >> b[i];
    F0R(i,2){
        F0R(j,3){
            cin >> a[j],a[j]-=b[j];
        }
        F0R(j,3) if(a[j]!=a[0]) return cw("No"), 0;
    }

    cw("Yes");
    return 0;
}
