#include <bits/stdc++.h>
using namespace std;
int r,d,x[2020];
int main() {
    cin>>r>>d>>x[2000];
    for (int i=2001; i<=2010; i++) {
        x[i]=x[i-1]*r-d;
        cout<<x[i]<<'\n';
    }
}