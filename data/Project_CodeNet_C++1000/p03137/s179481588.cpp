#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int M = 0;
    int N;
    cin >> N;
    cin >> M;
    vector<int> A(M,0);
    if(M == 1 || N >= M) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < M; i++) {
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    ll ans = A.at(M - 1) - A.at(0);
    //cout << ans << endl;
    for(int i = 0; i < M - 1; i++) {
        A.at(i) = A.at(i + 1) - A.at(i);
    }
    A.at(M - 1) = 0;
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    for(int i = 0; i < N - 1; i++) {
        //cout << A.at(i) << endl;
        ans -= A.at(i);
    }
    
    cout << ans << endl;


    return 0;
}