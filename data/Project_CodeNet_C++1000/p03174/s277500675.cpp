#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pub push_back
#define pob pop_back
#define loops(i, s, n) for (int i = s; i < n; i++)
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopr(i, s, e) for (int i = s; i >= e; i--)
#define eps 1e-9
#define loopitr(mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int, int>>
#define even_set 0xAAAAAAAA ... 1010101010
#define odd_set 0x55555555 ... 01010101
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vall(v) v.begin(), v.end()
#define mkp make_pair
#define ret return
#define cont continue
#define nl endl
#define ff first
#define ss second
#define cnt_bits __builtin_popcount
#define test  \
    int T;    \
    cin >> T; \
    while (T)
#define arrinit        \
    int n;             \
    cin >> n;          \
    int arr[n];        \
    loop(i, n)         \
    {                  \
        cin >> arr[i]; \
    }
#define init(arr, n, val)       \
    for (int i = 0; i < n; i++) \
        arr[i] = val;
const int mod = 1000000007;

bool arr[21][21];
int dp[(1<<21)];
int n;

int find(int mask){
    int i = cnt_bits(mask);
    if(i == n){
        ret 1;
    }

    if(dp[mask] != -1)
       ret dp[mask];
    int r = 0;
    loop(j, n){
        if(((mask>>j) & 1)  || arr[i][j] == 0 )  cont;

        (r += find(mask|(1<<j)))%=mod;
    }

    ret dp[mask] = r;
}

int main()
{
    fastio;
    
    cin>>n;
    loop(i, n)
      loop(j, n)
         cin>>arr[i][j];

    loop(i, (1<<n)){
        dp[i] = -1;
    }

    cout<<find(0)<<endl;
}