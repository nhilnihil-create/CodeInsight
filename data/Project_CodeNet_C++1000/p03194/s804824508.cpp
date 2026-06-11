#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>
 
using namespace std;
using ll = long long;
 
int main(void){
    ll n,p;
    cin>>n>>p;
    if( n == 1 ){
		cout << p << endl;
		return 0;
	}
    ll ans = 1;
    for(ll i =sqrt(p);i>1;--i){
        if(p%i == 0){
            int count = 0;
            while(p%i == 0){
               p /= i;
               count++;
            }
            if(count >= n) ans *= i;
            else for(int j=0;j<count;++j)p *= i;
        }
        
    }
    cout << ans << endl;
}
