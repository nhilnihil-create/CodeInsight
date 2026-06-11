#include <bits/stdc++.h>
using ld=long double;
using namespace std;
int main(){
    ld n,m,d,z=2;
    cin>>n>>m>>d;
    if(d==0)z=1;
    cout<<fixed<<setprecision(12)<<(m-1)*z*(n-d-d)/n/n+(m-1)*z*d/n/n;
}
