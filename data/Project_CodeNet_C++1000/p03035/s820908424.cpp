#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    int A,B;

    cin>>A>>B;

    if(A>=13){
        cout<<B<<endl;
    }
    else if(A<=5){
        cout<<"0"<<endl;
    }
    else{
        cout<<B/2<<endl;
    }


    return 0;
}
