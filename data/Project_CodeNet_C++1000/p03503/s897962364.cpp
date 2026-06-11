#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    int F[N][10];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++) cin >> F[i][j];
    }
    int P[N][11];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 11; j++) cin >> P[i][j];
    }
    long long ans = -1e18;
    for(int bit = 1; bit < (1 << 10); bit++){
        long long res = 0;
        vector<int> ope(10, 0);
        for(int i = 0; i < 10; i++){
            if(bit & (1 << i)) ope[i] = 1;
        }
        for(int i = 0;i < N; i++){
            int cnt = 0;
            for(int j = 0; j < 10; j++){
                if(ope[j] == F[i][j] && ope[j] == 1) cnt++;
            }
            res += P[i][cnt];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}