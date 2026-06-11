#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <iomanip>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }

const int maxn = 1e5 + 5;
int dp[maxn][4], n;
string s;

int f(int i, int x){
    if(i == n) return x == 3;
    if(dp[i][x] != -1){
        return dp[i][x];
    }
    int ret = 0;
    if(s[i] == 'A'){
        if(x == 0) ret = add(ret, f(i + 1, 1));
        ret = add(ret, f(i + 1, x));
    }
    else if(s[i] == 'B'){
        if(x == 1) ret = add(ret, f(i + 1, 2));
        ret = add(ret, f(i + 1, x));
    }
    else if(s[i] == 'C'){
        if(x == 2) ret = add(ret, f(i + 1, 3));
        ret = add(ret, f(i + 1, x));
    }
    else{
        if(x == 0) ret = add(ret, f(i + 1, 1));
        ret = add(ret, f(i + 1, x));
        if(x == 1) ret = add(ret, f(i + 1, 2));
        ret = add(ret, f(i + 1, x));
        if(x == 2) ret = add(ret, f(i + 1, 3));
        ret = add(ret, f(i + 1, x));
    }
    return dp[i][x] = ret;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> s;
  n = s.size();
  memset(dp, -1, sizeof dp);
  cout << f(0, 0);
}