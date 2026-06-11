#include <bits/stdc++.h>

using namespace std;

int main(){
    int FH, H, F, X;

    cin >> FH >> H >> F >> X;

    int ans = 0;
    for (int fhi=0; fhi <= FH; fhi++){
        for (int hi=0; hi <= H; hi++){
            for (int fi=0; fi <= F; fi++){
                if (500*fhi+100*hi+50*fi == X) ans++;
            }
        }
    }

    cout << ans << endl;
}