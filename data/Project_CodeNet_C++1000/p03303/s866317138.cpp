#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define fastio                          ios::sync_with_stdio(false);   cin.tie(0);   cout.tie(0);
#define input(arr, n)                   for(i=1; i<=n; i++) cin >> arr[i];
#define output(arr, n)                  for(i=1; i<=n; i++) {cout << arr[i] << " "; } cout << "\n";
#define print(cont)                     for(auto it : cont) {cout << it << " "; } cout << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



int main(){


    fastio;
    string s;
    cin >> s;
    int w;
    cin >> w;

    for(int i=0; i<s.size(); i+=w){
        cout << s[i];
    }
}