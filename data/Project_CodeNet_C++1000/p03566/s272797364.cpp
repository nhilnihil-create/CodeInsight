#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
int t[110], v[110];
int lm[202020];
int n, T;

bool f(double now, int since){
    for(int tm = since; tm <= T; tm++){
        if(lm[tm] < now) return false;
        now-=0.5;
    }
    return true;
}

int main(){
    cin >> n;
    rep(i, n){
        cin >> t[i];
        t[i] *= 2;
        T += t[i];
    }
    rep(i, n) cin >> v[i];
    int past = 0, st = 0;
    for(int i=0; i<=T; i++){
        if(past + t[st] == i){
            past += t[st];
            lm[i] = min(v[st], v[st+1]);
            st++;
        }else{
            lm[i] = v[st];
        }
        lm[i+1] = v[st];
    }

    double ans = 0;
    double now = 0;
    for(int i=0.; i<T; i++){
        if(f(now+0.5, i+1)){
            now += 0.5;
        }else if(!f(now, i+1)){
            now -= 0.5;
        }
        ans += now * 0.5;
        // cout << (i)/2. << "   "  << lm[i] << " " << now << endl;
    }
    cout << fixed << setprecision(15) << ans << endl;
}

