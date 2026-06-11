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
    int n,k,l = 0; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> acnt(n);
    
    sort(a.begin(),a.end());
    int cnt = 1;
    rep(i,n){
        if(a[i+1] == a[i]) cnt++;
        else{
            acnt[l] = cnt;
          //cout << acnt[l] << endl;  
          l++;
            cnt = 1;
        }
      //cout << cnt  << endl;
    }
  //cout << acnt[3];
  //rep(i,n) cout << acnt[i] << endl;
    ll ans = 0;
    sort(acnt.begin(),acnt.end());
    reverse(acnt.begin(),acnt.end());
    for(int i = k; i < n;i++){
        ans += acnt[i];
    }

    cout << ans << endl;
}