#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int nn=n/2+1;
    int k=1000;
    int n0,n1,n2;
    for (int i = 1; i <= nn; i++)
    {
        n0=i;
        n1=n-i;
        n2=0;
        n2+=n0%10;
        n2+=n1%10;
        n0=n0/10;
        n1=n1/10;
        n2+=n0%10;
        n2+=n1%10;
        n0=n0/10;
        n1=n1/10;
        n2+=n0%10;
        n2+=n1%10;
        n0=n0/10;
        n1=n1/10;
        n2+=n0%10;
        n2+=n1%10;
        n0=n0/10;
        n1=n1/10;
        n2+=n0%10;
        n2+=n1%10;
        n0=n0/10;
        n1=n1/10;
        n2+=n0%10;
        n2+=n1%10;
        if(n2<k){
            k=n2;
        }


    }
    cout<<k<<endl;
    
    

    


    return 0;
}