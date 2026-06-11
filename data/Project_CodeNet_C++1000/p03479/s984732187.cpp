#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll x,y;
    cin>>x>>y;
    ll c=0;
    while(x<=y) {
        x*=2;
        c++;
    }
    cout<<c<<endl;
}