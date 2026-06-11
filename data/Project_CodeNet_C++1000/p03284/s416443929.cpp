#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,K;
    cin>>N>>K;
    if(N%K==0)cout << 0 <<endl;
    else cout<< 1 <<endl;

    return 0;
}