#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,x,i,j,k,m=0,p;
    cin >> a >> b >> c >> x;
    
    for(i=0;i<=a;i++)
    {

        for(j=0;j<=b;j++)
        {

           for(k=0;k<=c;k++)
           {
               p=(i*500)+(j*100)+(k*50); 
               if(p==x)
               {
                    m++;
               }  
           }   
        }
    }          

    cout << m << endl;
 
    return 0;

}
