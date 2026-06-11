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


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    int n; cin >> n;
    vector<int> a(n+2);
    rep(i,n) cin >> a[i+1];

    ll sum = abs(a[1]),ans;
    rep(i,n-1){
        sum += abs(a[i+2] - a[i+1]);
    }
  	sum += abs(a[n]);
      
    for(int i=1;i<n+1;i++){
        ans = sum + abs(a[i+1] - a[i-1]) - (abs(a[i] - a[i-1]) + abs(a[i+1] - a[i]));
        cout << ans << endl;
    }
}

    
    