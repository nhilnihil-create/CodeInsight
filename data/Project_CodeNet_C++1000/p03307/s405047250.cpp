#include <iostream>

using namespace std;

int main()
{
    int r;
    
    cin>>r;
    if(r%2==0){
        cout<<r;
    }else{
        r=r*2;
        cout<<r;
    }

    return 0;
}