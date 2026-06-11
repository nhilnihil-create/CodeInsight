#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<tuple<string, int, int> > a;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        int p; cin >> p;
        p *= -1;
        a.push_back(tie(s, p, i));
    }

    sort(ALL(a));

    for(int i = 0; i < n; i++){
        cout << get<2>(a[i]) << endl;
    }



    return 0;
}
