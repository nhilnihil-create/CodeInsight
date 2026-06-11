#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N),y(M);
    rep(i,N) cin>>x[i];
    rep(i,M) cin>>y[i];
    if (X >= Y) {
        cout << "War" << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x[N - 1] < y[0] && x[N - 1] < Y && y[0] > X) cout << "No War" << endl;
    else cout << "War" << endl;   
    return 0;
}