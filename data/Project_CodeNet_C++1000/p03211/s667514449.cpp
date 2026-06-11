#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    string s; cin >> s;
    int n = s.size();
    int max_no = 999;
    for (int i = 0; i <= n-3; ++i) {
        int num = (s[i] - '0')*100 + (s[i+1] - '0')*10 + (s[i+2] - '0');
        max_no = min(max_no, abs(num - 753));
    }
    cout << max_no << endl;
    return 0;
}