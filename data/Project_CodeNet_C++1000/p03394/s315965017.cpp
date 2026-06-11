/* Be strong, be fearless, be beautiful :D
And believe that anything is possible :))
when you have the right people there
to support you :) */
//RTn_E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define _Sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define _file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define ll long long
#define ld long double
#define sp setprecision
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pii pair < int , int >
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 100;
const ll inf = 1e18;

//Main CODE :/\

vector < int > g , g4 , g2 , g3;
int main() {
    _Sync
    int n;
    cin >> n;
    if (n == 3)
        return cout << "2 5 63\n" , 0;
    if (n == 4)
        return cout << "2 5 63 20\n" , 0;
    if (n == 6)
        return cout << "2 3 6 9 12 4\n" , 0;
    for (int i = 4; i <= 3e4; i++){
        if (i % 6 == 0)
            g.pb(i);
        if (i % 6 == 2)
            g2.pb(i);
        if (i % 6 == 3)
            g3.pb(i);
        if (i % 6 == 4)
            g4.pb(i);
    }
    for (int i = 2e4 - n; i ; i--){
        if (i == 1)
            g.pop_back();
        else if (g2.size())
            g2.pop_back() , g4.pop_back() , i--;
        else if (g3.size() > 1)
            g3.pop_back() , g3.pop_back() , i--;
        else
            g.pop_back();
    }
    cout << 2 << " " << 3 << " ";
    for (auto u : g)
        cout << u << " ";
    for (auto u : g2)
        cout << u << " ";
    for (auto u : g3)
        cout << u << " ";
    for (auto u : g4)
        cout << u << " ";
    cout << "\n";
    return 0;
}
//The_End
//Game Over :D
