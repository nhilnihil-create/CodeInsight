#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
    long long ans = 5e18;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = 0; k < N; k++){
                for(int l = k + 1; l < N; l++){
                    long long xmin = min(x[i], x[j]);
                    long long xmax = max(x[i], x[j]);
                    long long ymin = min(y[k], y[l]);
                    long long ymax = max(y[k], y[l]);
                    int cnt = 0;
                    for(int m = 0; m < N; m++){
                        if(xmin <= x[m] && x[m] <= xmax && ymin <= y[m] && y[m] <= ymax) cnt++;
                    }
                    if(cnt >= K) ans = min(ans, (ymax - ymin) * (xmax - xmin));
                }
            }
        }
    }
    cout << ans << endl;
}