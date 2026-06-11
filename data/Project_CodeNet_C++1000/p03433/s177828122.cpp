#include <iostream>
using namespace std;

int main()
{
    int N,A,y;
    cin>>N;
    cin>>A;

    if(N<10001 && A<1001){
        if(N%500<=A)
            cout<<"Yes";
        else
            cout<<"No";
    }
    return 0;

}