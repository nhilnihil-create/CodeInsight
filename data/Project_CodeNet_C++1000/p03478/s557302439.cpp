#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b,i,j,v=0,c[100010],ans=0;
    cin >> n >> a >> b;
    for(i=1;i<=n;i++)
    {
        int z=i;
       while(1)
       {
           v+=z%10;
           z=z/10;
           if(z<1)
           {
               break;
           }
       }
        if(v>=a && v<=b)
        {
            ans+=i;
        }
        v=0;       
    }
    cout << ans << endl;

    return 0;

}
