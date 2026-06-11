#include<iostream>
using namespace std;
int main()
{
    short int m,n;
    cin>>m>>n;
    if(m+n==15) cout<<"+"<<endl;
    else if(m*n==15) cout<<"*"<<endl;
    else cout<<"x"<<endl;
    return 0;
}
