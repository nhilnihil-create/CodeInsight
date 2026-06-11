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
    P<P<string, int>, int> p[n];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int point; cin >> point;
        p[i] = make_pair(make_pair(s, -point), i);
    }


    sort(p, p + n);
    for(int i = 0; i < n; i++){
        cout << p[i].second + 1 << endl;
    }


    return 0;
}
