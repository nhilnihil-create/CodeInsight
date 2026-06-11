#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = unsigned long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    ll  ans=0;

    //rep(i,n) cout << a[i] << endl;
    sort( a.begin(), a.end(), greater<ll>() );

    for( ll i = 0; i < a.size(); i++ ){
      if(a[i]%2 == 0 ){
        int tmp = a[i];
        while(1){
          if( tmp < 1 || tmp%2 != 0 ) break;
          tmp /= 2;
          ans ++;
        }
      }
      //cout << a[i] << " " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
