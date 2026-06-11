#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int N;
    int K;
    cin >> N >> K;
    int A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cout << ((N-1) + (K-1) - 1) / (K-1) << endl;

    return 0;
}
    