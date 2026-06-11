#include <bits/stdc++.h>
using namespace std;

double t[105], v[105], st[105];
int main(){
    int n;
    cin >> n;
    double sum = 0.0;
    for(int i = 0; i < n; i++){
        cin >> t[i+1];
        st[i+1] = st[i] + t[i+1];
    }
    st[n+1] += st[n];
    for(int i = 0; i < n; i++) cin >> v[i+1];
    double ans = 0.0, prev = 0.0;
    for(double i = 0.5; i <= st[n]; i += 0.5){
        double cur = 100;
        for(int j = 0; j <= n+1; j++){
            if(j >= 1 && st[j-1] <= i && i <= st[j]){
                cur = min(cur, (double)v[j]);
            }
            if(st[j] < i){
                cur = min(cur, (double)(v[j] + (i - st[j])));
            }
            if(j >= 1 && st[j-1] > i){
                cur = min(cur, (double)(v[j] + (st[j-1] - i)));
            }
        }
        ans += (cur + prev) * 0.25;
        prev = cur;
    }
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}