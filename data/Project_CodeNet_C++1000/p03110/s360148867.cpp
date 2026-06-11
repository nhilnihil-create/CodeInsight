#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
int main()
{
    optimize();
    int n,i;
    double p,t=0.0;
    string st;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>p>>st;
        if(st=="BTC")
            p=380000.0*p;
        t+=p;
    }
    cout<<t<<"\n";
    return 0;

}
