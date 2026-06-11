#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int X, Y;
    cin >> X >> Y;
    vector<int> x(N);
    vector<int> y(M);
    for(int n=0; n<N; n++) {
        cin >> x[n];
    }
    for(int m=0; m<M; m++) {
        cin >> y[m];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    if(X<y[0] && y[0]<=Y && x[N-1]<y[0]) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }


    return 0;
    
}