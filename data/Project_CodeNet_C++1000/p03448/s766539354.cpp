#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < (n);i++)
ll INF = 1000000010; 
const ll MOD = 1000000007;


int main(){ 
    int a, b, c, x, ans = 0;
    cin >> a >> b >> c >> x;
    rep(i,a+1) rep(j,b+1) rep(k,c+1) if(500 * i + 100 * j + 50 * k == x) ans++;

    cout << ans << endl;
} 