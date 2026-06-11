#include <bits/stdc++.h>
using namespace std;
int main(void){
    int i=0,n,x,d,j,k,saidai=0,c=0,l;
    cin >> x;
    if(x==1)
    {
        cout << x << endl;
        return 0;
    }
    for(i=2;i<x;i++)
    {
        j=i;
        while(j<=x)
        {
           if(j*i>x)
           {
               break;
           }
           j=j*i;
           c++;
        }
        if(saidai<j && c>0)
        {
            saidai=j;
        }
        c=0;
    }
    cout << saidai << endl;
    return 0;
}
