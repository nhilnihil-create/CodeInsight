#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    long long ans = ((n-m)*100 + m*1900) * pow(2.0, m); 
    cout << ans << endl;
    return 0;
}