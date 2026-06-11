#include <iostream>
using namespace std;
int main(void){
    long long n,a,b,c,d,e,m;
    cin >> n >> a >> b >> c >> d >> e;
    m = min(a,min(b,min(c,min(d,e))));
    cout << (n+m-1)/m+4;
}