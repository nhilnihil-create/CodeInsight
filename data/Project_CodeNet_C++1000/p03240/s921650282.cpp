#include <iostream>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int x[N], y[N], h[N];
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    int acx, acy, ah;
    for(int cx=0; cx <=100; cx++){
        for(int cy=0; cy<=100; cy++){
            // 0を無視して高さを仮決めする
            int H = -1;
            for(int i=0; i<N; i++){
                if(h[i] == 0) continue;
                int tmp = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                if(H == -1) H = tmp;
                if(H != tmp){
                    H = -2;
                    break;
                }
            }
            if(H == -2) continue;
            for(int i=0; i<N; i++){
                if(h[i] != 0) continue;
                int tmp = H - abs(x[i]-cx) - abs(y[i]-cy);
                if(tmp > 0){
                    H = -2;
                    continue;
                }
            }
            if(H != -2){
                acx = cx;
                acy = cy;
                ah = H;
            }
        }
    }

    cout << acx << " " << acy << " " << ah << endl;

    return 0;
}
