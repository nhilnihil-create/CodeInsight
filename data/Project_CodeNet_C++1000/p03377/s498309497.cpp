#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, x;
    cin >> a >> b >> x;
    if(a + b < x || x < a)cout << "NO" << endl;
    else cout << "YES" << endl;
}