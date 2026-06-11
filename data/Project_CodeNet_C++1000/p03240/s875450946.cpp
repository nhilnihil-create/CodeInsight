#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    V<int> x(n), y(n), h(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            int H = -1;
            for(int k = 0; k < n; k++){
                if(h[k] > 0){
                    int tmp = h[k] + abs(x[k] - i) + abs(y[k] - j);
                    if(H == -1){
                        H = tmp;
                    }else{
                        if(H != tmp){
                            H = -2;
                            break;
                        }
                    }
                }
            }
            if(H == -2) continue;

            for(int k = 0; k < n; k++){
                if(h[k] == 0){
                    int tmp = abs(x[k] - i) + abs(y[k] - j);
                    if(H > tmp){
                        H = -2;
                        break;
                    }
                }
            }
            if(H == -2) continue;

            cout << i << " " << j << " " << H << endl;
            return 0;
        }
    }

    return 0;
}
