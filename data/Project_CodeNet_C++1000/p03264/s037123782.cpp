#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    int K;

    cin>>K;

    if(K%2==0){
        cout<<(K/2)*(K/2)<<endl;
    }
    else{
        cout<<(K/2+1)*(K/2)<<endl;
    }

    return 0;
}
