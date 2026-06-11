#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,squ,value;
    cin>>n;
    if(n>=1 && n<=10e9)
    {
        squ = sqrt(n);
    value = squ * squ;
    cout<<value<<endl;
    }
}
