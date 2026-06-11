#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    int A[5],k;
    string flag="Yay!";

    cin>>A[0]>>A[1]>>A[2]>>A[3]>>A[4]>>k;

    rep(i,5){
        for(int j=i;j<5;j++){
            if(A[j]-A[i]>k){
                flag=":(";
            }
        }
    }

    cout<<flag<<endl;

    return 0;
}
