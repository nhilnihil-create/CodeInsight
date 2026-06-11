#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int N,D,X;
    cin>>N>>D>>X;
    vector<int>A(N);
    rep(i,N){
        cin>>A[i];
        X+=(D-1)/A[i]+1;
    }
    cout<<X<<endl;
}
