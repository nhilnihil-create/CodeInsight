#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];
    int count=X;
    for (int i=0; i<N; i++){
        count+=(D-1)/A[i]+1;
    }
    cout << count << endl;
}
