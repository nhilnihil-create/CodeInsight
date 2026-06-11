#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, j, k;
    int N, x[100], y[100], h[100];
    cin >> N;
    for(i=0; i<N; i++) cin >> x[i] >> y[i] >> h[i];

    for(int Cx=0; Cx<=100; Cx++){
        for(int Cy=0; Cy<=100; Cy++){
            int H = -1; // -1:未確定
            int Hmax = 2e9; // h[i]=0である点から要求されるHの上限
            bool success = true;
            for(i=0; i<N; i++){
                int d = abs(Cx-x[i]) + abs(Cy-y[i]);
                if(h[i] > 0){
                    int H2 = h[i] + d;
                    if(H > 0 && H != H2){
                        success = false;
                        break;
                    }else{
                        H = H2;
                    }
                }else{
                    Hmax = min(Hmax, d);
                }
            }
            if(success && H <= Hmax){
                cout << Cx << " " << Cy << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}
