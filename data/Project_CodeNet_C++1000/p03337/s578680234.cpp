#include <iostream>
using namespace std;
int main()
{
    int a,b,A,B,n,m,l;
    cin>>A>>B;
   m=max(A+B,A-B);
   n=max(m,A*B);
   cout<<n;
    return 0;
}
