#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    int a[2],n;
    cin >> n >> a[0] >> a[1];
    sort(a,a+2);
    cout << a[0] << " ";
    if(n - (a[0]+a[1]) < 0)cout << (a[0]+a[1]) - n << endl;
    else cout << 0 << endl;
}