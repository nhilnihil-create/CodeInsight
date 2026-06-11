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
    ll n,m; cin >> n >> m;
    ll ans;
    if(n <= 1 || m <= 1){
      	if(n == 1 && m == 1) ans = 1;
      	else ans = max(n,m) - 2;
    }else{ 
        ans = (n-2) * (m-2);
    }
    cout << ans << endl;
}