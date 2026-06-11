#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, T t){return v2<T>(r, vector<T>(c, t));}

int n;
void solve(){
    cin >> n;
    vector<int> c(n), s(n), f(n);
    for(int i = 0; i < n-1; i++) cin >> c[i] >> s[i] >> f[i];

    for(int i = 0; i < n; i++){
        int t = 0;
        for(int j = i; j < n-1; j++){
            if(t < s[j]) t = s[j]+c[j];
            else if(t%f[j] == 0) t += c[j];
            else t += f[j]-t%f[j] + c[j];
        }
        cout << t << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
