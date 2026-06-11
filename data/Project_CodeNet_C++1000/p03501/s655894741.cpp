#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,a=0,b=0;
    cin >> n >> a >> b;
    if(n*a>b) cout << b << endl;
    else cout << n*a << endl;
    return 0;
}