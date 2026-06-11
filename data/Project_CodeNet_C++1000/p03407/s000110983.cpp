#include <iostream>

using namespace std;

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    if(A>=1&&B<=500&& C>=1&&C<=1000)
    if(A+B>=C)
    cout<<"Yes"<<endl;
    else if(A+B<C)
    cout<<"No"<<endl;

    return 0;
}