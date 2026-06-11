#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n),h(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            int hight = -1;
            for(int k = 0; k < n; k++){
                if(h[k]){
                    hight = abs(x[k]-i)+abs(y[k]-j)+h[k];
                    break;
                }
            }
            bool ok = true;
            for(int k = 0; k < n; k++){
                if(max(hight-abs(x[k]-i)-abs(y[k]-j),0) != h[k]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << i << " " << j << " " << hight << endl;
                return 0;
            }
        }
    }
    return 0;
}