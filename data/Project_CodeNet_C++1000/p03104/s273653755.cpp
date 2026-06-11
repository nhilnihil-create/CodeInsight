#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define int long long
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define rep(i, x, n) for (int i = x; i < n; ++i)
#define mp make_pair
#define fi first
#define se second
#define ii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vii vector<pair<int, int>>
#define reverse(s) reverse(s.begin(), s.end())
#define ld long double
#define vs vector<string>
#define inf INT_MAX
#define vc vector<char>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define vb vector<bool>
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define ub(a, x) upper_bound(a.begin(), a.end(), x) 
#define vvi vector<vi>
#define mine(a) min_element(a.begin(),a.end())
#define maxe(a) max_element(a.begin(), a.end())
#define iota(a,i) iota(a.begin(),a.end(),i)
int findXOR(int n)
{
    int mod = n % 4;
    if (mod == 0)
        return n;
    else if (mod == 1)
        return 1;
    else if (mod == 2)
        return n + 1;
    else if (mod == 3)
        return 0;
}
int findXOR(int l, int r){
    return (findXOR(l - 1) ^ findXOR(r));
}
signed main() {
    fastio;
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a;
        return 0;
    }
    a = max(a, (int)1);
    cout << findXOR(a, b);
    return 0;
}