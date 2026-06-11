#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c,d,q=0;
    cin>>n;
    a=n/10;
    b=n%10;
    c=a%10;
    d=a/10;
    if(b==1){q++;}
    if(c==1){q++;}
    if(d==1){q++;}
    cout<<q;
   return 0;
}
