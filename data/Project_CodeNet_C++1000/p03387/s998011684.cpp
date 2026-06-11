#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    if((2*a[2]-a[0]-a[1])%2==0)cout << (2*a[2]-a[0]-a[1])/2 << endl;
    else cout << 2+(2*a[2]-a[0]-a[1])/2 << endl;
}