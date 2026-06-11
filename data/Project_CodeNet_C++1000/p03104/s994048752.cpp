#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    ll a,b;
    cin >> a >> b;
    ll ans_a,ans_b,fans;
    if ((a)%2 == 0) ans_a = ((a)/2)%2;
    else ans_a = (((a)/2)%2)^(a-1);
    if ((b+1)%2 == 0) ans_b = ((b+1)/2)%2;
    else ans_b = (((b+1)/2)%2)^b;
    fans = ans_a ^ ans_b;
    
    cout << fans << endl;
    
     
    
}

