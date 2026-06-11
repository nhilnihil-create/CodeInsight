#include <iostream>
using namespace std;
int main()
{
    int m,n,a;
    cin>>n>>a;
    m=n%500;
    if(m<=a){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
