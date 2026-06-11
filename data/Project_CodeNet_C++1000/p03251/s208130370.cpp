#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N), y(M);
    for (int i=0; i<N; i++) cin >> x[i];
    for (int i=0; i<M; i++) cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x[N-1] >= y[0]){
        cout << "War" << endl;
    } else{
        for (int i=y[0]; i>x[N-1]; i--){
            if (i > X && i <= Y){
                cout << "No War" << endl;
                return 0;
            }
        }
        cout << "War" << endl;
    }
    return 0;
}