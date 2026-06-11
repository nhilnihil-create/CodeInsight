#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;

    vector<int> x(N);
    vector<int> y(M);
    for(int i=0;i<N;i++) {
        cin >> x[i];
    }
    for(int i=0;i<M;i++) {
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if((x[x.size()-1] < y[0])
        && (X<y[0])
        && (x[x.size()-1] < Y)
        && X < Y){
        cout << "No War\n";
    } else {
        cout << "War\n";
    }

    return 0;
}
