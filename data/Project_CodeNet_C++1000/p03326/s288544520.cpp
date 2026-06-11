#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    long x[N], y[N], z[N];
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    long ans = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                long temp[N]; fill(temp, temp + N, 0);
                for(int m=0; m<N; m++){
                    temp[m] = (2 * i - 1) * x[m] + (2 * j - 1) * y[m] + (2 * k - 1) * z[m];
                }
                sort(temp, temp + N, greater<long>());
                long s = 0;
                for(int l=0; l<M; l++) s += temp[l];
                ans = max(ans, s);
            }
        }
    }
    cout << ans << endl;
    return 0;
}