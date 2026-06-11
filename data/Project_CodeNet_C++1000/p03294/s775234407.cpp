#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
    int n;
    cin >> n;
    ll ans = 0LL;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        ans+=(tmp-1);
    }
    cout << ans << endl;
    
    return 0;

}
