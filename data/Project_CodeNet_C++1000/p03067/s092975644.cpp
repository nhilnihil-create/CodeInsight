#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[2],c;
    cin >> a[0] >> a[1] >> c;
    sort(a,a+2);
    if(a[0] <= c&&c <= a[1])cout << "Yes" << endl;
    else cout << "No" << endl;
}