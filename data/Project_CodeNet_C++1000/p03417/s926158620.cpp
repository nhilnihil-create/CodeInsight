#include <bits/stdc++.h>

using namespace std;
 

 
int main()
{
    long long int N,M;
    cin>>N>>M;
 
    if(N==1 && M==1) 
        cout<<1;   
    else if(N==1 && M>1) 
        cout<<M-2;
    else if(N>1 && M==1) 
        cout<<N-2;
    else
    {
        cout<<M*N - 2*(M+N) + 4;
    } 
}