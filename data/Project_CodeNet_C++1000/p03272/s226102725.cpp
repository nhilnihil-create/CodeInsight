#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define fastio                              ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define read                                freopen("input.txt", "r", stdin);
#define write                               freopen("output.txt", "w", stdout);
#define nl                                  '\n'
#define mem(v,n)                            memset(v,n,sizeof(v))
#define debug(x)                            cerr << #x << " = " << x << nl
#define LCM(a,b)                            (a / __gcd(a,b) ) *b
#define GCD(a,b)                            __gcd(a,b)

#define ll                                  long long
#define ull                                 unsigned long long
#define vi                                  vector<int>
#define pb                                  push_back
#define vpii                                vector<pair<int, int>>
#define vpll                                vector<pair<ll, ll>>
#define mp                                  make_pair
#define ff                                  first
#define ss                                  second
#define all(v)                              v.begin(), v.end()
#define rsort(v)                            sort(v.rbegin(), v.rend())

using namespace std;

const double pi = 2*acos(0.0);



int main(){
    int n, p;
    cin >> n >> p;
    cout << n-p+1;
}













