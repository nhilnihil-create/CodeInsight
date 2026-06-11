#include <bits/stdc++.h>
using namespace std;

int main(){
    //１～ｎで、各位の和がＡ～Ｂであるものの総和
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    int cnt = 0;
    for(int m = 1; m <= N; m++){
        int k=0;
        cnt = m;
        while(true){
            k = k + cnt % 10;
            if(cnt / 10 == 0) break;
            cnt /= 10;
        }
        if(A <= k && k <= B) ans += m;
    }

    cout << ans << endl;
}