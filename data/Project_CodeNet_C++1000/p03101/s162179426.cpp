#include <iostream>
using namespace std;
int main(void){
    int a,b,A,B,ans=0;
    cin>>a>>b>>A>>B;
    ans+=a*B+(b-B)*A;
    ans=a*b-ans;
    cout<<ans<<endl;
}