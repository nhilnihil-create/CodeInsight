#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> P;

int main() {
    long long N,M;
    cin >> N >> M;
    vector<P>A(N);
    for(long long i = 0; i < N; i++) {
        long long a,b;
        cin >> a >> b;
        A[i].first = a;
        A[i].second = b;
    }
    sort(A.begin(),A.end());
    long long ans = 0;
    long long cnt = 0;
    while(M != 0) {
        if(M > A[cnt].second) {
            ans+=A[cnt].first*A[cnt].second;
            M-=A[cnt].second;
        }
        else {
            ans+=M*A[cnt].first;
            M = 0;
        }
        cnt++;
    }
    cout << ans << endl;
}
