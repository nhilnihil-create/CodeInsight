#include <bits/stdc++.h> 
#define ll long long int  
using namespace std;
int main() {
    ll x,y; 
    cin >> x >> y;  
    ll c=0; 
    while(x<=y)
    {
       c++ ; 
       x*=2;
    } 
    cout << c << endl;
    return 0;
}
