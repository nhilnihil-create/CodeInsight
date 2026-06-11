#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a;
    float b,c;
    int d;
    cin>>b>>c;
    a=(c/2)+(b/2);
    d=a;
    if(a-d<0.5){
        cout<<d;
    }
    else{
        cout<<d+1;
    }

}
