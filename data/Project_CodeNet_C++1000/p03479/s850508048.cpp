#include <iostream>
using namespace std;
 
typedef long long ll;
 
int main() {
    ll x,y;cin>>x>>y;
    ll ans = 0;
 
    while(y>=x){
        ++ans;
        y/=2;
    }
    cout<<ans<<endl;
	return 0;
}