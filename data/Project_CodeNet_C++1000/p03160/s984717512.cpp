#include <bits/stdc++.h>
#define ll long long
using namespace std;


void frog(int *A,int n)
{
    ll t[n+1];
    
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        t[i]=0;
        else if(i>=3){
                t[i]= min( (t[i-1]+abs(A[i]-A[i-1])),
                    (t[i-2]+abs(A[i]-A[i-2])) );
    }
        else t[i]=t[i-1]+abs(A[i]-A[i-1]);
    }
    
    std::cout  <<  t[n];
    
}

int main() {
    int n;
    cin >>n;
    int A[n+1];

    for(int i=1;i<=n;i++)
    cin >>A[i];

    frog(A,n);
}