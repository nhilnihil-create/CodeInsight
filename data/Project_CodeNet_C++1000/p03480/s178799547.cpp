#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
#include <vector>
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
#define umin( x , y ) x = min( x , (y) )
#define set multiset
#define null NULL
#define ort (b+s)/2

using namespace std;

typedef long long Lint;
typedef long double db;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<db,db> dd;
typedef pair<int,string> is;

const int maxn = 6000020;
const int K = 320;
const int MOd = 1e9 + 7;

Lint a, ar[maxn];

void solve() {
    string s;
    cin >> s;
    int a = s.size();
    int ans = a;
    for(int i=0;i+1<a;i++)
        if(s[i] != s[i+1])
            umin( ans, max( i+1, a-i-1 ) );
    printf("%d\n",ans);
}

int main(  ) {


	int n = 1;
	//scanf("%d",&n);
	while( n-- ) solve();

	return 0;
}