#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int N,A[110];
    int imin = 1000000001,imax = 0;

    cin >> N;

    rep(i,N)
        cin >> A[i];

    rep(i,N){
        imax = max(imax,A[i]);
        imin = min(imin,A[i]);
    }

    cout << imax-imin << endl;

    return 0;
}