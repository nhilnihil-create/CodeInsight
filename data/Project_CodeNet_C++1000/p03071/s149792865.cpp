#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int a,b;
    cin >> a >> b;

    if(a>b) cout << 2*a-1 << endl;
    else if(a<b) cout << 2*b-1 << endl;
    else cout << 2*a << endl;
}