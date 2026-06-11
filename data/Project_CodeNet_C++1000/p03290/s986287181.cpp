#include <bits/stdc++.h>
using namespace std;

int main(){
    int D,G;
    cin >> D >> G;
    int p[D],c[D];

    for(int i = 0;i < D;i++){
        cin >> p[i] >> c[i];
    }
    int ans = INT32_MAX;
    for(int bit = 0;bit < (1<<D);bit++){
        int Gtmp = 0;
        int anstmp = 0;
        for(int i = 0;i < D;i++){
            if(bit & (1<<i)){
                Gtmp += p[i] * (i+1)*100 + c[i];
                anstmp += p[i];
            }
        }

        int j;
        for(j = D-1;j >= 0;j--){
            if(!(bit & (1<<j))){
                break;   
            }
        }

        for(int k = 0;k < p[j];k++){
            if(Gtmp >= G){
                break;
            }
            Gtmp += (j+1)*100;
            anstmp++;
        }
        if(Gtmp >= G){
            if(ans > anstmp)ans = anstmp;
        }
    }
    cout << ans << endl;

}