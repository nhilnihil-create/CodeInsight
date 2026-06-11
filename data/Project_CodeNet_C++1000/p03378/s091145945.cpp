#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,M,X,a,maxnm;
    cin >> N >> M >> X;
    
    maxnm = max(N,M) + 1;
    vector<int> A(maxnm,0);

    for(int i=1;i<=M;i++) {
        cin >> a;
        A[a] = 1;
    }

    
    for(int i=1;i<=N;i++) {
        A[i] = A[i-1]+A[i];
    }

    cout << min(A[X-1],A[N]-A[X-1]) << endl;
    return 0;
}
