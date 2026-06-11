#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;



int main() {
    int a,b;
    cin>>a>>b;
    int payment=b;
    if(a<=5)payment=0;
    else if(a<=12)payment=payment/2;

    cout<<payment<<endl;

    return 0;
}