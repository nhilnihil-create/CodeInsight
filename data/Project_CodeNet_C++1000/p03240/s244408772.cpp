#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n; cin >> n;
    vector<int> x(n), y(n), h(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    int ans_x, ans_y, ans_h, xxx, yyy, hhh;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){

            vector<int> HH;
            for(int k=0; k<n; k++){
                // 0 の場合は、必ずしも下の式成り立たない
                if(h[k] > 0){
                    HH.push_back(h[k] + abs(x[k] - i) + abs(y[k] - j));
                    xxx = x[k];
                    yyy = y[k];
                    hhh = h[k];
                }
            }

            if(HH.size() == 1){
                cout << xxx << " " << yyy << " " << hhh << endl;
                return 0;
            }

            int count = 0;
            for(int kk=0; kk<HH.size()-1; kk++){
                // 要素数1の場合はどうなるか。
                if(HH[kk] != HH[kk+1]) count++;
            }

            if(count == 0){
                ans_x = i;
                ans_y = j;
                ans_h = HH[0];
                break;
            }

        }
    }

    cout << ans_x << " " << ans_y << " " << ans_h << endl;
    return 0;
}
