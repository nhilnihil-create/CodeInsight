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
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};
#define pb push_back 

int main(){
    int n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin >> a[i];
        a[i] -= (i+1);
        b[i] = a[i];
    }
    sort(b.begin(),b.end());

    ll m = b[n/2], ans = 0;
    rep(i,n){
        ans += abs(a[i] - m);
    }
    cout << ans << endl;
}