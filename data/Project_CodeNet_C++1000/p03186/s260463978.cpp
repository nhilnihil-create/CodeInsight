#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll t ;

    if(c<=a+b)t=b+c;
    else t=a+2*b+1;
    cout << t << endl;
    return 0;

}