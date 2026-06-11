#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    double n,m,d;cin>>n>>m>>d;
    double an;
    if(d==0)an=n/n/n*(m-1);
    else an=2*(n-d)/n/n*(m-1);
    cout<<setprecision(12)<<an<<endl;

}





