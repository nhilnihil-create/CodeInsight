#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c;
    cin>>a>>b>>c;
    if(a<c&&b>c||a>c&&b<c) cout<<"Yes";
    else cout<<"No";
}
