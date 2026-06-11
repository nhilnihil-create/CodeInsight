#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    cin >> N;
    vector<int> A;
    A.push_back(0);
    rep(i, N) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    A.push_back(0);
    int fare = 0;
    rep(i, N+1) fare += abs(A[i+1] - A[i]);
    rep(i, N) {
        int t = fare;
        t -= abs(A[i] - A[i+1]);
        t -= abs(A[i+1] - A[i+2]);
        t += abs(A[i] - A[i+2]);
        cout << t << endl;
    }
    return 0;
}