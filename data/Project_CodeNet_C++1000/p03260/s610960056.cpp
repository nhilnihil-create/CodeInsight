#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b){
        a=a*a*b;
    }
    if(b>a){
       b=b*b*a;
    }
    if(a%2==0 || b%2==0){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}
