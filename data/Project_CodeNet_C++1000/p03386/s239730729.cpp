#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,k;
    cin>>a>>b>>k;
    if(b-a+1 < 2*k) {
        for(int i=a; i<=b; i++) {
            cout<<i<<"\n";
        }
    }
    else {
        for(int i=a; i<a+k; i++) {
            cout<<i<<"\n";
        }
        for(int i=b-k+1; i<=b; i++) {
            cout<<i<<"\n";
        }
    }
}