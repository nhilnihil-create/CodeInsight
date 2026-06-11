//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1000 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

string s1,s2;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s1 >> s2;
    reverse(s1.begin(),s1.end());
    cout << (s1==s2 ? "YES" : "NO") << '\n';

    return 0;

}