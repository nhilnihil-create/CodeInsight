#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    int c,d,x;

    c=N%K;
    if(c==0){
        cout<<0;
    } else{
        d=c-1;
        x=c-d;
        cout<<x;
    }


    return 0;
}