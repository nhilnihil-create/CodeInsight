#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin>>n>>a>>b;

    int ma,mi;

    ma = min(a,b);
    if(n>a+b) mi = 0;
    else mi = a+b-n;

    cout<<ma<<' '<<mi<<endl;

    return 0;
}