#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long int n,y,b,i,j,k,v=0,d[100010],saisyou=10000,ans=0,t;
    cin >> n >> y;
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=n;k++)
            {
                b=i+j+k;
                if(b==n && i*10000+j*5000+k*1000==y)
                {
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;*/
    v=1000*n;
    b=n;
    if(v==y)
    {
        cout << "0" << " " << "0" << " " << n << endl;
        return 0;
    }

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                b=n-(i+j);
                t=i+j+b;
                if(v+9000*i+j*4000==y && n==t && b>=0)
                {
                    cout <<  i << " " <<  j << " "  << b << endl;
                    return 0;
                }
            }
        }
     
    cout << "-1" << " " << "-1" << " " << "-1" << endl; 

    return 0;

}
