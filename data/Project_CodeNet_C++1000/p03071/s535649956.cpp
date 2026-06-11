#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    int A,B,sum=0;

    cin>>A>>B;

    rep(i,2){
        if(A>B){
            sum+=A;
            A-=1;
        }
        else{
            sum+=B;
            B-=1;
        }
    }
    cout<<sum<<endl;


    return 0;
}
