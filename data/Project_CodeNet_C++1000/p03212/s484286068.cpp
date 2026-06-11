#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

set<int> st;
int N; 
void dfs(string S = "", int a = 0, int b = 0, int c = 0) {
    if(S.size() && stoll(S) > N) return;
    if(a > 0 && b > 0 && c > 0) {
        st.insert(stoll(S));
    }
    dfs(S + '3', a + 1, b, c);
    dfs(S + '5', a, b + 1, c);
    dfs(S + '7', a, b, c + 1);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    dfs();
    cout << st.size() << endl;


    return 0;
}
