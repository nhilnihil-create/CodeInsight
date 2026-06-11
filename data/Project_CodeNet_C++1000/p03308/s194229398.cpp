#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,a[1000],saidai=0,m,n;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            m=abs(a[i]-a[j]);
                if(m>saidai)
                {
                    saidai=m;
                }
        }
    }
    cout << saidai << endl;
    return 0;

}
