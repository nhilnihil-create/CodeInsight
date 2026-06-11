#include<bits/stdc++.h>
using namespace std;

int main()
{
    double num;
    long long int n;
    int a;
    
    cin>>n;
    num=sqrt(n);
    n=num;
    num=num-n;
    
    cout<<(n*n);
    return 0;
}