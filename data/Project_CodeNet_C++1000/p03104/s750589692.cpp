#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll f(ll x){
    ll tmp = 0;
    if((x/2)%2 == 1)    tmp = 1;
    if(x%2 == 1)    tmp ^= 1;
    else            tmp ^= x;
    return tmp;
}

int main(){
    ll a, b;    cin>>a>>b;
    ll ans = (a==0)?f(b):f(b)^f(a-1);
    cout << ans << endl;
}
