#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int>x(N);
    vector<int>y(N);
    vector<int>h(N);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> h[i];
        if(h[i] > 0) {
            cnt = i;
        }
    }
    int takasa = 0;
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            bool ok = true;
            takasa = h[cnt]+abs(x[cnt]-i)+abs(y[cnt]-j);
            for(int k = 0; k < N; k++) {
                if(h[k] != max(takasa-abs(x[k]-i)-abs(y[k]-j),0)) {
                    ok = false;
                }
            }
            if(ok) {
                cout << i << " " << j << " " << takasa << endl;
                return 0;
            }
        }
    }       
}