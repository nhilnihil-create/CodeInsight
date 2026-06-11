#include <bits/stdc++.h>
using namespace std;
#define int long long

double n,m;
int d;

signed main(){
    cin>>n>>m>>d;
    m--;
    double res=m/n;
    cout<<setprecision(20)<<(d==0?res:res*2.0*(n-d)/n)<<endl;
}