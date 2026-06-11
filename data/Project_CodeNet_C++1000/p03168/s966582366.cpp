#include <bits/stdc++.h>
/*#include <ctime>
#include <list>
#include <numeric>
#include <bitset>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <utility>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <iomanip>
#include <limits>*/

using namespace std;


/// Bismilahir Rahmanir Rahim


typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef short int si;
typedef unsigned short int usi;
typedef pair <int, int> pii;


#define CASE false
#define File false
#define TEST false
#define BUFFER true
#define TIME false
#define DEBUG true
#define SET_GEN false
#define _ << " " <<
#define __ << "\n"
#define ff first
#define ss second
#define RANGE(a, b) (rand() % (b-a+1) + a)


const double pi = acos(-1.);
const double eps = 1e-7;
const int high = 2e9;
const int inf = 2147483647;
const int _inf = -2147483648;
const lli INF = 1e18;
const int mod = 1e9+7;
const int maxn = 1e4;


void delay(int sec); // DEBUG


void solution(void)
{
    int n;

    cin >> n;

    vector <double> dp(n+1);
    dp[0] = 1;

    for(int i = 1; i <= n; ++i) {
        double p;
        cin >> p;
        for(int j = i; j >= 0; --j) {
            dp[j] = (j == 0? 0: dp[j-1]*p) + dp[j]*(1-p);
        }
    }

    double ans = 0;

    for(int i = (n+1)>>1; i <= n; ++i)
        ans += dp[i];

    cout << fixed << setprecision(10) << ans __;




    return ;
}

int main(int argc, char *arv[])
{
    #if File
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    #if BUFFER
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #endif

    #if SET_GEN
    srand((unsigned int) time(0));
    #endif

    #if prep
    prep_calc();
    #endif

    int t = 1;

    #if CASE
    int cnt = 1;
    #endif

    #if TEST
    cin >> t;
    #endif

    #if TIME
    clock_t start_time, end_time;
    double time_elapsed;
    #endif


    while(t--) {

        #if TIME
        start_time = clock();
        #endif

        #if CASE
        cout << "Case " << cnt++ << ": ";
        #endif

        solution();

        #if TIME
        end_time = clock();

        time_elapsed = (double) (end_time - start_time) / CLOCKS_PER_SEC;

        cout << "\nRuntime: " << fixed << setprecision(7) << time_elapsed << "\n";
        #endif
    }


    return 0;
}

void delay(int sec)
{
    int mili_sec = 1000 * sec;

    clock_t start_time = clock();

    while (clock() < start_time + mili_sec);

    return ;
}
/*

*/
