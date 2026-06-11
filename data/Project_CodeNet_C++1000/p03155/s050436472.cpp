#include <iostream>

int main(){
    using namespace std;
    int N,H,W;
    cin>>N>>H>>W;

    int ans=(N-H+1)*(N-W+1);
    cout<<ans<<endl;
    
    return 0;
}