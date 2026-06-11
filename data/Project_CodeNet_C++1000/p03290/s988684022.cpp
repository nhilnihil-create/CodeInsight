#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

const int MAX_d = 10, INF = 1e8;
int d, g, p[MAX_d], c[MAX_d];
int ans = INF;
int main(){
    cin >> d >> g;
    rep(i, d) cin >> p[i] >> c[i];

    for(int bit = 0; bit < (1 << d); bit++){
        bitset<MAX_d> e(bit);
        int sum=0, cnt=0, maxPtr=-1;
        rep(i, d){
            if(e.test(i)){
                sum += c[i] + (i+1)*p[i]*100;
                cnt += p[i];
            }
        }
        int num=-1;
        rep(i, d){
            if(!e.test(i) && maxPtr < i){
                maxPtr = i;
                num = p[maxPtr];
            }
        }
        
        while(sum < g && num > 1){
            if(maxPtr == -1) break;
            sum += 100 * (maxPtr+1);
            num--;
            cnt++;
        }
        if(sum >= g && ans > cnt) ans = cnt;
    }
    cout << ans << endl;
}