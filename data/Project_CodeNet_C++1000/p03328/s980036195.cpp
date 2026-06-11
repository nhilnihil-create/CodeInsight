#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin>>a>>b;
    int d = b-a;
    int ans= (d-1)*(d-2)/2+d-1-a;
    cout<<ans;
    
}
