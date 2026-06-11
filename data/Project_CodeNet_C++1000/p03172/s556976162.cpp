/*

                         YATIN KWATRA                       _03_08_14


Let's Hoop..



                             __oooo
       //  /    o
     / /  |      o
    | /  |__     o
   | |   __/    o
   | |  /  oooo
  | /  |  _______________________
 | |   | |_______________________|
||    |___ \__/\_/\_/\/\/\/\/\/\/
||    |    \ \/\/\/\/\/\/\/\/\/
||    \     \ \/\/\/\/\/\/\/\/
| |    |    |  \/\/\/\/\/\/\/
 | |    |   |   \/\/\/\/\/\/
  | |    \_/    |\/\/\/\/\/|
   \ \     \__  |/\/\/\/\/\|
    |         \
   |           |
   |           |
   |           |
   |           |
    |          |
    |         |
     |________|
     |________|
    ||         |
   | |          |
  |  /          |
 |  /          /
 /\|__________|
|   /       /
|  |       /
| |       |
 \ |      \
  \ \      \
    \ \     |
      \ \    |
        \ \  |_
          \\_/ \
           |    |
           |   /
           |  |
           |_/



HOOPER_4_LYF..

*/

// AC BAKSHI RABBA

// #pragma GCC optimize "trapv"

#include <bits/stdc++.h>
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795

using namespace std;

void INPUT()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

/*

   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
   -> Read the Question and the sample test cases carefully
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..



o- - -  \o          __|
   o/   /|          vv`\
  /|     |              |
   |    / \_            |
  / \   |               |
 /  |                   |


   Thats what I call a Tappu / Blocked_shot / Rejection...


   Time to Code Now.....
*/

const int N = 101;
const int M = 100005;

ll dp[N][M];
ll v[N];

void solve()
{

  int n, k;
  cin >> n >> k;

  fo(i, 0, n - 1) cin >> v[i];

  fo(i, 0, n)
  {
    fo(j, 0, k) dp[i][j] = 0;
  }

  fo(i, 0, v[0]) dp[0][i] = 1;
  fo(i, 0, n - 1) dp[i][0] = 1;

  fo(i, 1, n - 1)
  {
    vll pre(k + 1, 0);

    pre[0] = dp[i - 1][0];
    fo(j, 1, k) pre[j] = (pre[j - 1] + dp[i - 1][j]) % mod;

    // dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ...... + dp[i-1][j-v[i]]
    // this is the sum we are calculating,but in could be k*k in worst
    // case, so we can store prefix sums to get pre[j] - pre[j-v[i]-1] for
    // each index i

    fo(j, 1, k)
    {
      dp[i][j] = pre[j];
      if (j > v[i]) dp[i][j] -= pre[j - v[i] - 1];

      dp[i][j] = (dp[i][j] % mod + mod) % mod;
    }
  }

  cout << dp[n - 1][k] << endl;
}

int main() {

  FIO
  INPUT();

  int t;
  t = 1;
// cin >> t;

  fo(i, 0, t - 1)
  {
    solve();
  }
  return 0;
}
