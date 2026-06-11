#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int n;
    cin >> n;
    vector<int> t(n+1,0),v(n);
    for (int i = 0;i < n;++i) cin >> t[i+1];
    for (int i = 0;i < n;++i) cin >> v[i];
    for (int i = 0;i < n;++i) t[i+1] += t[i];
    int s = t[n]*2+1;
    vector<double> u(s);
    for (int i = 0;i < s;++i) u[i] = i*0.5;
    for (int i = 0;i < s;++i) u[i] = min(u[i],(s-i-1)*0.5);
    for (int i = 0;i < n;++i) {
        for (int j = t[i]*2;j < t[i+1]*2+1;++j) u[j] = min(u[j],(double)v[i]);
    }
    for (int i = 0;i < n+1;++i) {
        for (int j = t[i]*2;j < s;++j) u[j] = min(u[j],u[t[i]*2]+(j-t[i]*2)*0.5);
    }
    for (int i = 1;i < n+1;++i) {
        for (int j = 0;j < t[i]*2;++j) u[j] = min(u[j],u[t[i]*2]+(t[i]*2-j)*0.5);
    }
    double ans = 0;
    for (int i = 0;i < s;++i) ans += u[i];
    cout << fixed << setprecision(12) << ans/2 << endl;
}