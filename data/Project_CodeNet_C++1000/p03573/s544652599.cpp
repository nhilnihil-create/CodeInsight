#include <iostream>

using namespace std;

int main()
{
    int A , B , C;
    cin>>A>>B>>C;
    if(-100<=A && A<=100 && -100<=B && B<=100 && -100<=C && C<=100)
    {
        if(A==B && C!=A)
        {
            cout<<C<<endl;
        }
        else if(A==C && B!=A)
        {
            cout<<B<<endl;
        }
        else if(B==C && A!=B)
        {
            cout<<A<<endl;
        }
    }
    return 0;
}
