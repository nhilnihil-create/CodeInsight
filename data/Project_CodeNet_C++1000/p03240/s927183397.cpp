#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int  n,i,j,k,x,H,xx;
    cin>>n;
    long long int   X[n],Y[n],h[n];
    int indx;
    for(i=0; i<n; i++)
    {
        cin>>X[i]>>Y[i]>>h[i];
        if(h[i] > 0)
        {
            indx= i;
        }
    }

    for(i=0; i<=100; i++)
    {
        for(j=0; j<=100; j++)
        {
            H=h[indx]+abs(X[indx]-i)+abs(Y[indx]-j);
            bool its_ok=true;
            for(k=0; k<n; k++)
            {
                xx=(H-abs(X[k]-i)-abs(Y[k]-j));
                if(xx<0)   xx=0;

                if(xx!=h[k])
                {
                    its_ok=false;
                    break;
                }
            }
            if(its_ok)
            {
                cout<<i<<' '<<j<<' '<<H<<endl;
                return 0;
            }
        }
    }
    return 0;
}
