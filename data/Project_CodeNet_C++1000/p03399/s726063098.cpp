#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
int main(void){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int train, bus;
    train = min(a, b);
    bus = min(c, d);
    
    int ans = train + bus;
    
    cout << ans << endl;
    return 0;
}
