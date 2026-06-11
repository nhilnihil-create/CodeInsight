#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,N) {
        cin >> V[i];
    }
    int sum = 0;
    sort(V.begin(),V.end());
    rep(j,N-1) {
        sum += V[j];
    }
    if (sum > V[N - 1]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
}
