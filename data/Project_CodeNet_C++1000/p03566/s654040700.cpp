#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)


int main(){
    int n;
    cin >> n;
    vector<double> t(n);
    vector<double> v(n);
    cin >> t[0];
    for(int i = 1; i < n; i++){
        cin >> t[i];
        t[i] += t[i-1];
    }
    double total = t[n-1];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    v.push_back(0);
    double tt = 0.0;
    double speed = 0.0;
    double ans = 0.0;
    for(int i = 0; i < n; i++){
        while(tt < t[i]){
            tt += 0.5;
            double limit = t[i] - tt + v[i+1];
            for(int j = i; j < n; j++){
                limit = min(limit, t[j] - tt + v[j+1]);
            }
            double old_speed = speed;
            speed = min(min(speed+0.5, limit),v[i]);
            ans += (old_speed + speed)*0.5*0.5;
        }
    }
    printf("%.12f\n",ans);
    return 0;
}
