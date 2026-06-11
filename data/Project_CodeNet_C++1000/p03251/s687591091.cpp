#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<int> x(N);
    vector<int> y(M);

    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> y[i];
    }

    int mx = *max_element(x.begin(), x.end());
    int my = *min_element(y.begin(), y.end());

    if(X < Y && X < my && mx < Y && mx < my) {
        cout << "No War" << endl;
        return 0;
    }

    cout << "War" << endl;
}