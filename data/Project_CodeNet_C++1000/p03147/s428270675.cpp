#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {

    int n; cin >> n;
    int Min = 101;
    int p = 0;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = 0;
    bool flag = false;

    while(1) {
        Min = 101;
        p = 0;
        rep(i, n) {
            if(h[i] == 0){
                for(int j = p; j < i; j ++){
                      if(Min != 101) h[j] -= Min;
                }
                if(Min != 101)ans += Min;
                p = i+1;
                Min = 101;

            }else{
                Min = min(Min,h[i]);
            }

            if(i == n-1){
                for(int j = p; j <= i; j ++){
                    if(Min != 101) h[j] -= Min;
                }
                if(Min != 101) ans += Min;
            }

        }

        for(int k =  0; k < n; k ++){
            if(h[k] != 0) break;
            if(k == n-1) flag = true;
        }

        if(flag) break;
    }

    cout << ans;

    return 0;
}









