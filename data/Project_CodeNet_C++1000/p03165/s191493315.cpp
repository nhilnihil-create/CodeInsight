#define watch5(a,b,c,d,e) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d << " | "<<#e<<": "<<e<<endl;
#define watch4(a,b,c,d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define watch3(a,b,c) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<endl;
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define sharingan cerr << "\n-------------------------------------------\n\n";
#define watch2(a,b) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<< endl;
#define Yup ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(a) cerr <<#a<<": "<<a<<endl;
#define __gcd(a, b) __algo_gcd(a, b)
#define PI 3.14159265358979323846
#define mod 1000000007
#include "bits/stdc++.h"
using namespace std;
#define int long long

string s, t;

int dp[3001][3001];

int f( int i, int j ){
    if( i == s.size() || j == t.size() )return 0;
    if( dp[i][j] != -1 )return dp[i][j];
    int len = 0;
    if( s[i] == t[j] ){
        len = 1 + f(i+1, j+1);
    }
    else{
        len = f(i+1, j);
        len = max(len, f(i, j+1));
    }
    dp[i][j] = len;
    return len;
}

void print( int i, int j, int l ){
    if( l == 0 )return;
    if( s[i] == t[j] && dp[i][j] == l ){
        cout << s[i];
        print(i+1, j+1, l-1);
    }
    else{
        if( dp[i+1][j] == l ){
            print(i+1, j, l);
        }
        else{
            print(i, j+1, l);
        }
    }
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    int l = f(0, 0);
    print(0, 0, l);
}