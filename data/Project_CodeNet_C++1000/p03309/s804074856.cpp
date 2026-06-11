#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for_(i,0,N) {
        cin >> A[i];
        A[i] -= i + 1;
    }

    sort(ALL(A));
    int b = A[N/2];
    lint ans = 0;
    for_(i,0,N) ans += abs(A[i] - b);
    cout << ans << endl;
}