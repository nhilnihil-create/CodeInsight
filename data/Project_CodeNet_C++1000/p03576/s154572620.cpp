#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<int> x(N), y(N);
    for(int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    }

    int64_t ans = INT64_MAX;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                for(int l=0; l<N; l++) {
                    int64_t x_min = x[i];
                    int64_t x_max = x[j];
                    int64_t y_min = y[k];
                    int64_t y_max = y[l];
                    int cnt = 0;
                    for(int m=0; m<N; m++) {
                        if(x_min <= x[m] && x[m] <= x_max && y_min <= y[m] && y[m] <= y_max) {
                            cnt++;
                        }
                    }
                    if(cnt == K) {
                        ans = min(ans, (x_max-x_min)*(y_max-y_min));
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
