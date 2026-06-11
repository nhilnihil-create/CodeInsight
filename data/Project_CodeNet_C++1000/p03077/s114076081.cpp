#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    long long n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    long long m = min({a,b,c,d,e});
    cout << (n+m-1)/m + 4 << endl;
    return 0;
}