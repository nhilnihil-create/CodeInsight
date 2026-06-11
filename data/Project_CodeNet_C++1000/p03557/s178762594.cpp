#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;

int bi_search1(ll key,vector<ll> &a){
    
    ll left = 0;
    ll right = (ll)a.size();
    if(a[0]>=key) return -1 ;
    while (right-left>1)
    {
      ll mid = (right+left)/2;
      if(a[mid]>=key){
          right = mid;
      }else{
          left = mid;
      }
    }
    return left;
}

int bi_search2(ll key,vector<ll> &a){
    
    ll left = -1;
    ll right = (ll)a.size()-1;
    if(a[right]<=key) return right+1 ;
    while (right-left>1)
    {
      ll mid = (right+left)/2;
      if(a[mid]<=key){
          left = mid;
      }else{
          right = mid;
      }
    }
    return right;
}

int main() {
    int n;
    cin >> n ;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

   for(int i=0;i<n;i++) cin >> a[i];
   for(int i=0;i<n;i++) cin >> b[i];
   for(int i=0;i<n;i++) cin >> c[i];

   sort(a.begin(),a.end());
   sort(c.begin(),c.end());

   ll ans= 0 ;
   for(int i=0;i<n;i++){
       ll a_ind = bi_search1(b[i],a)+1;
       ll c_ind = n-bi_search2(b[i],c);
       //cout << a_ind << " " << c_ind << endl;
       ans+=a_ind*c_ind;
   }

   cout << ans << endl ;

    return 0 ;
}