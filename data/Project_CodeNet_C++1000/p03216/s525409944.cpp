#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++){
        int k;
        cin >> k;
        int64_t d = 0, m = 0, dm = 0;
        int64_t ans = 0;
        for (int i = 0; i < n; i++){
            if (i - k >= 0){
                if (S[i - k] == 'D'){
                    d--;
                    dm -= m;
                }
                if (S[i - k] == 'M')
                    m--;
            }

            if (S[i] == 'D'){
                d++;
            }
            if (S[i] == 'M'){
                dm += d;
                m++;
            }
            if (S[i] == 'C'){
                ans += dm;
            }
        }

        cout << ans << endl;
    }
}