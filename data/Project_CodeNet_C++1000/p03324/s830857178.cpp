#include <iostream>
using namespace std;
int main(void){
    int d,n;
    cin >> d >> n;
    if(n==100) n++;
    if(d==0) cout << n;
    else if(d==1) cout << 100*n;
    else cout << 10000*n;
}