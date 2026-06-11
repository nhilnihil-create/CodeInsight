#include <bits/stdc++.h> 
using namespace std; 
 
int main() 
{ 

    int n,k;
    cin>>n>>k;

    int wk;
    if(n%2==0)
        wk=n/2;
    else
        wk=n/2+1;

    if(wk>=k)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0; 
} 