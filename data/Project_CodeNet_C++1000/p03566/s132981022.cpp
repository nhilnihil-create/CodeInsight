#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<iomanip>

using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long

int main(){
    int n; cin >> n;
    vector<int> T, V; int max_s = 0;
    T.push_back(0);
    rep(i, n){
        int t; cin >> t; max_s += t; T.push_back(max_s);
    }
    rep(i, n){
        int v; cin >> v; V.push_back(v);
    }
    double limv[40005];
    rep(s, max_s+1) limv[s] = min(s, max_s-s);
    rep(s, max_s+1){
        limv[2*s] = min(s, max_s-s);
        limv[2*s+1] = min((double)s+0.5, (double)(max_s-s)-0.5);
    }
    rep(i, n){
        rep(s, max_s + 1){
            double lime;
            if(s < T[i]) lime = V[i]+T[i]-s;
            else if(s <= T[i+1]) lime = V[i];
            else lime = V[i]-T[i+1]+s;
            limv[2*s] = min(limv[2*s], lime);

            double u = s + 0.5, limo;
            if(u < T[i]) limo = V[i]+T[i]-u;
            else if(u <= T[i+1]) limo = V[i];
            else limo = V[i]-T[i+1]+u;
            limv[2*s+1] = min(limv[2*s+1], limo);
        }
    }
    double ans = 0;
    rep(s, max_s*2 + 1){
        ans += (double)limv[s];
    }
    cout << fixed << setprecision(10);
    cout << (ans/2) << endl;
}