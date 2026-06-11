#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int D, G;
    cin >> D >> G;

    int p[D], c[D];
    for(int i=0; i<D; i++){
        cin >> p[i] >> c[i];
    }

    int ans = 1000000005;
    // 1のやつをを全部解き、あまったら残りの中で一番点高いやつを解く
    for(int s=0; s<pow(2, D); s++){
        int total = 0;
        int cnt = 0;
        // cout << "---------" << endl;
        // cout << bitset<2>(s) << endl;
        for(int i=0; i<D; i++){
            if(((s>>i)&1) == 0) continue;
            total += 100*(i+1)*p[i] + c[i];
            cnt += p[i];
            // cout << i << " " << 100*(i+1)*p[i] + c[i] << endl;
        }
        if(total >= G){
            ans = min(ans, cnt);
            continue;
        }

        bool fl = false;
        for(int i=D-1; i>=0; i--){
            if(((s>>i)&1) == 1) continue;
            int add = ceil((G-total)/(100*(i+1)));
            if(add == 0) add++;
            if(add < p[i]){
                cnt += add;
                fl = true;
            }
            break;
        }

        if(fl) ans = min(ans , cnt);
    }

    cout << ans << endl;

    return 0;
}
