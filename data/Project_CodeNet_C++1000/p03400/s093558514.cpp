#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N;
    int D, X;
    cin >> N;
    cin >> D >> X;

    vector<int>syouhi(D);
    vector<int>A(N);

    for (int i=0; i<N; i++)cin >> A[i];

    for (int i=0; i<N; i++){
        int j=0;
        int ai = A[i];
        while(ai*j  < D){
            syouhi[ai*j]++;
            j++;
        }
    }
    int ans = X;
    for (int i=0; i<D; i++)ans += syouhi[i];
    cout << ans << endl;
}