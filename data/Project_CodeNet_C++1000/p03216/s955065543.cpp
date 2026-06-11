#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int Q;
    cin >> Q;
    for(int q=0;q<Q;++q){
        int k;
        cin >> k;
        i64 ans = 0;
        i64 d = 0, m = 0, dm = 0;
        for(int i=0;i<n;++i){
            if(i >= k){
                if(s[i-k] == 'D'){
                    d--;
                    dm -= m;
                }else if(s[i-k] == 'M'){
                    m--;
                }
            }
            if(s[i] == 'D'){
                d++;
            }else if(s[i] == 'M'){
                m++;
                dm += d;
            }else if(s[i] == 'C'){
                ans += dm;
            }
        }
        cout << ans << endl;
    }

    return 0;
}