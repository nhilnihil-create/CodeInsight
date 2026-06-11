#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    while(Q--){
        int K;
        cin >> K;

        int64_t d = 0, m = 0, dm = 0, ans = 0;
        for(int i=0; i<N; i++){
            if(i-K >= 0){
                if(S[i-K] == 'D'){
                    d--;
                    dm -= m;
                }else if(S[i-K] == 'M'){
                    m--;
                }
            }
            
            if(S[i] == 'D'){
                d++;
            }else if(S[i] == 'M'){
                m++;
                dm += d;
            }else if(S[i] == 'C'){
                ans += dm;
            }
        }

        cout << ans << endl;
    }
    return 0;
}