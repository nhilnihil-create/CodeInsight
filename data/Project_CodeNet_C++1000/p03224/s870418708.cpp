//pantyhose(black) + glasses = infinity

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << '\n';
#define BP() cerr << "OK!\n";
#define PR(A, n) {cerr << #A << " = "; for (int _=1; _<=n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; for (int _=0; _<n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define FILE_NAME "data"

const int MAX_N = 100002;

int n;
vector<int> s[MAX_N];

int main() {
	#ifdef GLASSES_GIRL
		freopen(FILE_NAME".inp", "r", stdin);
		freopen(FILE_NAME".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int x;
    for (x=1; x*(x-1)/2<n; ++x);
    if (x*(x-1)/2!=n) {
        cout << "No";
        return 0;
    }
    int nEdge = 0;
    for (int i=1; i<=x; ++i) {
        for (int j=i+1; j<=x; ++j) {
            s[i].push_back(++nEdge);
            s[j].push_back(nEdge);
        }
    }
    cout << "Yes\n" << x << '\n';
    for (int i=1; i<=x; ++i) {
        cout << s[i].size() << ' ';
        for (auto v : s[i])
            cout << v << ' ';
        cout << '\n';
    }
}

