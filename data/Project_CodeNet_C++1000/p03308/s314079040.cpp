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
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());

    cout << a[n-1] - a[0] << endl;
}