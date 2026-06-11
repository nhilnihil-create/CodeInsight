#include<bits/stdc++.h>

using namespace std;

int main(void){
    int A,B;
    cin>>A>>B;
    int ans=max(max(2*A-1,2*B-1),A+B);
    cout<<ans<<endl;
    return 0;
}
