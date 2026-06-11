#include <bits/stdc++.h>
using namespace std;
long A,B;
main()
{
    cin>>A>>B;
    long ans=0;
    while(A%4&&A<B)ans^=A++;
    while(B%4!=3&&A<B)ans^=B--;
    if(0<=B-A&&B-A<4)ans^=A++;
    cout<<ans<<endl;
}