#include <bits/stdc++.h>

/*
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <ctype.h>
*/


using namespace std;

typedef pair<int , int > pii;
typedef pair<long , long> pll;
typedef pair<pii , int > piii;
typedef pair<pll , long > plll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector <pii> vii;
typedef vector<pll> vll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
typedef long long int lli;
typedef double d;
typedef float f;
typedef string s;
typedef char ch;
typedef pair<int,ll> pill;

#define loop(n) for(int i = 0; i < (n); i++)
#define lp(x , s , e) for(int x = (s); x < (e); x++)
#define lpe(x , s , e) for(int x = (s); x <= (e); x++)
#define readline(s) getline(cin,s)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;
#define MP make_pair
#define PB push_back
#define all(a) a.begin(),a.end()
#define clr(x , val) memset((x) , (val) , sizeof(x))
#define endl '\n'

ll power(ll a, ll b)
{
    ll res = 1;
    for(int i = 0; i<b; i++)
       res *= a;

    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int a , b;
	cin >> a >> b;
	cout << (a - 1) * (b - 1) << endl;
    return 0;
}
