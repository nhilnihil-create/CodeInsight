#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
int main(void){
    double a, b, c;
    cin >> a >> b >> c;
    double s = (a + b + c) / 2.0;
    
	double ans = sqrt(s*(s-a)*(s-b)*(s-c)); 
    
    cout << ans << endl;
    return 0;
}