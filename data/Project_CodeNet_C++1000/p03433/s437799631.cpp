#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,a;
    cin>>n>>a;

    if((n%500)==0)
    {
      cout<<"Yes"<<endl;
    }
    else if((n%500)<=a)
    {
        cout<<"Yes"<<endl;   
    }
    else
    {
       cout<<"No"<<endl; 
    }
    

}