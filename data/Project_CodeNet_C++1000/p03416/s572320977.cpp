#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>

using namespace std;

bool check(int n) {
    string s = to_string(n);

    int l = 0;
    int r = s.size() - 1;

    while(l < r) {
        if(s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }

    return true;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int counter = 0;

    for(int i = a; i <= b; i++) {
        if(check(i)) counter++;
    }

    cout << counter << endl;
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}