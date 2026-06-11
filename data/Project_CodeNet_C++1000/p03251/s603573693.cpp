#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N, M, X, Y;
    vector<int> x(100), y(100);
    cin >> N >> M >> X >> Y;
    rep(i, N) cin >> x[i];
    rep(i, M) cin >> y[i];

    sort(x.begin(), x.begin()+N);
    sort(y.begin(), y.begin()+M);

    if(max(X,x[N-1]) < min(Y,y[0])){
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }

}