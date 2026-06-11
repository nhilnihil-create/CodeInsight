#include <iostream>

using namespace std;

int main()
{
    int A,B,X;
    cin>>A>>B>>X;
    if(A==X){
        cout<<"YES"<<endl;
    }
    else if((A>X) ||(X>(A+B))){
        cout<<"NO"<<endl;
    }
else{
    cout<<"YES"<<endl;
}
    return 0;
}
