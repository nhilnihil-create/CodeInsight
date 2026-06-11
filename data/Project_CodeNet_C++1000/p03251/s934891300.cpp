#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector <int> x(N+1);
    vector <int> y(M+1);
    for (int i=0; i<N; i++) cin >> x.at(i);
    x.at(N) = X;
    for (int i=0; i<M; i++) cin >> y.at(i);
    y.at(M) = Y;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int x_max, y_min;
    x_max =  x.at(x.size()-1);
    y_min =  y.at(0);
    if (x_max<y_min) cout << "No War";
    else cout << "War";
}