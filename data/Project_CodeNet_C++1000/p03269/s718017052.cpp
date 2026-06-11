#include <bits/stdc++.h>

using namespace std;
int L,n,m,sl,T;
int main()
{
  
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>L;
    for (int i=0;i<20;++i) if ((L>>i)&1) {n=i+1;sl++;}
    sl--;m=(n-1)*2+sl;
    cout<<n<<' '<<m<<'\n';
    for (int i=1;i<n;++i) {cout<<i<<' '<<i+1<<' '<<0<<'\n';
                           cout<<i<<' '<<i+1<<' '<<(1<<(i-1))<<'\n';
    }
    for (int i=19;i>=0;--i)
    if ((L>>i)&1)
    {

        if (i+1==n) {T=T+(1<<i);continue;}
        cout<<i+1<<' '<<n<<' '<<T<<'\n';
        T=T+(1<<i);
    }

    return 0;
}
