#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
typedef long long ll;

template<class A, class B> bool mmin(A& a, B b) {if (b < a) {a = b; return 1;} return 0;}
template<class A, class B> bool mmax(A& a, B b) {if (b > a) {a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        int ind = -1;
        for (int j = 0; j < i; j++) {
            if (j == b[j]) ind = j;
        }
        if (ind == -1) {
            cout << "-1\n";
            return 0;
        }
        ans.pb(ind + 1);
        vector<int> now;
        for (int j = 0; j < i; j++) {
            if (j != ind) now.pb(b[j]);
        }
        b = now;
    }
    reverse(all(ans));
    for (auto z : ans) cout << z << '\n';
    return 0;
}
