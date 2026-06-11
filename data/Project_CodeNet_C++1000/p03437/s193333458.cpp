#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e18;
const ll N =(300+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

void solve(){
    ll x,y;
    cin >> x >> y;
    if(x%y != 0){
        cout << x << endl;
    }
    else cout << -1 << endl;
    // for(int i = x;i<=200;i++){
    //     if(i%x==0 && i%y!=0){
    //         cout << i << endl;
    //     }
    // }
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    

 
     ll tt=1;   
    while(tt--){    
        solve();
    }    
}