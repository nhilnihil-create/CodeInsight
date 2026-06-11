#include <iostream>

using namespace std;

int main()
{
    int a,b,x,y,sum;
    cin>>a>>b;
    x=a/b;
    y=a%b;
    if(y!=0){
        sum=1+x;
    }else sum=x;
    cout<<abs(sum-x);
    return 0;
}
