#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>

#include<deque>
#define pi 3.141592653589793238
#include<chrono>

#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
     //cin >> T;
    while (T--) {
       ll a, b, c ,d ,e, k;
       cin >> a>> b >> c >>d >> e >> k;
       if(e - a > k){
           cout << ":(";
       }
       else{
           cout << "Yay!";
       }
    }

    return 0;
}
