#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    rep(n, 1, 3501){
        rep(w, 1, 3501){
            ll si = N*n*w;
            ll bo = 4*w*n - N*(n+w);
            if(bo == 0) continue;
            if(si % bo != 0) continue;
            ll h = si / bo;
            //cerr << h << endl;
            if(h > 0){
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
    return 0;
}