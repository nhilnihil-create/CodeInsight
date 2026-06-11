#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    int n;
    cin >> n;
    vi c(n),s(n),f(n);
    rep(i,n-1){
        cin >> c[i] >> s[i] >> f[i];
    }

    rep(i,n-1){
        int ans = s[i] + c[i];//i+1へ
        reps(j,i+1,n-1){
            //最初の電車が出る前につく
            if(ans < s[j]) ans = s[j]+c[j];//s[j]まで待つ
            else{//最初の電車が出た後につく
                int tmp = ans % f[j];
                if(tmp == 0)
                    ans = ans + c[j];
                else
                    ans = ans + (f[j]-tmp) + c[j];
            }
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
    return 0;
}
