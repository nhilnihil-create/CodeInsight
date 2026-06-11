#include <iostream>
using namespace std;
int main()
{
int A,B,X;
cin >> A >> B >> X ;
if(A>X) cout<<"NO";
if(A==X)cout<<"YES";
if(A<X){
if((A+B) >= X){
        cout<<"YES";
}
else cout<<"NO";
}
    return 0;
}
