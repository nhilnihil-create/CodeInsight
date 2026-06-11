///Astalavista Code........~CodeSlayer007
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define fe first
#define se second
#define double long double
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define PT(x) cout << (x) << endl
#define last(x)  prev(x.end())
#define PTT(x) cout << (#x) << " is " << (x) << endl
#define lets_go ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int IM = 1e15 + 37;
const double PI = 3.1415926535897932384;
inline void PP(int n) { cout << n << " ";}
void PV(vi v) { for (int i = 0 ; i < v.size() ; i++) cout << v[i] << " " ; cout << endl;}
void PVV(vii v) {for (int i = 0 ; i < v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << ' ' ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
inline void op() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// <=================================================================================================================================
// <=================================================================================================================================


signed  main() {
    //op();
    lets_go

    int n;
    cin >> n;
    int dp[n + 10][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0; 
    for (int i = 1; i <= n; i++){
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] += max(dp[i - 1][2], dp[i - 1][1]);
        dp[i][1] += max(dp[i - 1][2], dp[i - 1][0]);
        dp[i][2] += max(dp[i - 1][0], dp[i - 1][1]);
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    PT(ans);




    /**/
    return 0;
}