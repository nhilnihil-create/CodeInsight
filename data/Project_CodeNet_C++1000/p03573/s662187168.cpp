#include <iostream>
using namespace std;
int main(){
    int A,B,C,Diff;
        cin>>A>>B>>C;
        if(A==B)
            Diff=C;
        else if (A==C)
            Diff=B;
        else
            Diff=A;
        cout<<Diff;
    return 0;
}