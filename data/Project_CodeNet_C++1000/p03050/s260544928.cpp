#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[2] = {-1, 1};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i < sqrt(n); i++){
        if(n%i==0 && n%(n/i-1)!=0){
            ans+=n/i-1;
            //cout << i << endl;
        }
    }
    cout << ans << endl;
    //for(ll i = 0; i < a.size(); i++)
      //  cout << a[i] << endl;
    return 0;
}
