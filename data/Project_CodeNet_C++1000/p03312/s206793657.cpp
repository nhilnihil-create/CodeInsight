#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 2e5 + 5;
lint A[MAX_N], S[MAX_N];

int main(){
    int N; cin >> N;
    for(int i=1;i<=N;i++) {cin >> A[i]; A[i] += A[i-1];}

    lint ans = 1e15;
    for(int i=2;i<N-1;i++){
        int j = distance(A, lower_bound(A, A+i+1, A[i]/2));
        int k = distance(A, lower_bound(A+i+1, A+N+1, A[i]+(A[N]-A[i])/2));

        lint a, b, c, d;
        if(abs(A[i]-2*A[j]) < abs(A[i]-2*A[j-1])) {a = A[j], b = A[i]-A[j];}
        else {a = A[j-1], b = A[i]-A[j-1];}
        if(abs(A[N]-2*A[k]+A[i]) < abs(A[N]-2*A[k-1]+A[i])) {c = A[k]-A[i], d = A[N]-A[k];}
        else {c = A[k-1]-A[i], d = A[N]-A[k-1];}
        ans = min(ans, max(max(a, b), max(c, d))-min(min(a, b), min(c, d)));
    }

    cout << ans << endl;
    return 0;
}