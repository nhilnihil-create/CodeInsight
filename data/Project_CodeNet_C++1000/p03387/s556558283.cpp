#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    int A,B,C;cin>>A>>B>>C;
    int top=max(A,max(B,C));
    int bottom=min(A,min(B,C));
    int middle=A+B+C-top-bottom;
    int ans=top-middle;
    bottom+=top-middle;
    if((top-bottom)%2==0){
        ans+=(top-bottom)/2;
    }
    else{
        ans++;
        ans+=(top-bottom+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
