#include<iostream>
using namespace std;

int c(int a,int b)
{
    return (a+b);
}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(c(n,a)>=b){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}
