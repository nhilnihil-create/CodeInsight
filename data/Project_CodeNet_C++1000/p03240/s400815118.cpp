#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    vector<int> H(N);
    rep(i, N){
        cin >> X[i] >> Y[i] >> H[i];
    }
    bool ok = true;
    int cH;
    int cx, cy;
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            ok = true;
            int hf = 0;
            int xf, yf;
            int counter = 0;
            while(hf == 0){
                xf = X[counter];
                yf = Y[counter];
                hf = H[counter];
                counter++;
                cH = hf + abs(i-xf) + abs(j-yf);
            }
            for (int n = 0; n < N; n++){
                int x = X[n];
                int y = Y[n];
                int h = H[n];
                if(h == 0){
                    int Hnow = abs(i-x) + abs(j-y);
                    if(Hnow < cH){
                        ok = false;
                        break;
                    }
                } else {
                    int Hnow = h + abs(i-x) + abs(j-y);
                    if(Hnow != cH){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                cx = i;
                cy = j;
                break;
            }
        }
        if(ok)break;
    }

    cout << cx << " " << cy << " " << cH << endl;

    return 0;
}