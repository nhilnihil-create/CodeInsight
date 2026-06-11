#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define inf 1e17
#define MAX_SIZE 1000005 

void pr(int arr[], int size) 
{ for (ll i=0; i < size; i++) {printf("%d ", arr[i]); }cout << endl;}

int main () {
  ll t = 1;
//   cin >> t;
  while(t--){
    ll n , k;
    cin >> n >> k;
    ll a[n];
    ll freq[n+1] = {};
    for(ll i = 0;i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    vector<ll> u ;
    for(ll i = 0;i < n+1; i++){
         if(freq[i]){
             u.push_back(freq[i]);
         }
    }
    
    ll cnt =  u.size() ;
    if(cnt <= k){
        cout << 0 << endl;
    }
    else{
        sort(u.begin() , u.end());
        ll sum = 0;
        for(ll i = 0;i < cnt - k;i++){
            sum += u[i];
            // cout << u[i] << endl;
        }
        cout << sum << endl;
    }
    }
    return 0;
}
