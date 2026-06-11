#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    int A,B,C;

    cin>>A>>B>>C;

    if(A*C<B){
        cout<<C<<endl;
    }
    else{
        cout<<B/A<<endl;
    }

    return 0;
}
