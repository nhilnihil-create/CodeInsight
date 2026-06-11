#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int n,k,q,ng = 1e9;
    int a[2010],b[2010],c[2010];
    cin >> n >> k >> q;
    for (int i = 0;i < n;++i) scanf("%d",&a[i]);
    a[n] = -1;
    int ans = 1e9;
    for (int i = 0;i < n;++i) if (a[i] < ng) {
        int cnt1 = 0,cnt2 = 0;
        for (int j = 0;j < n+1;++j) {
            if (a[j] < a[i]) {
                sort(b,b+cnt1);
                for (int l = 0;l < cnt1-k+1;++l) c[cnt2++] = b[l];
                cnt1 = 0;
            } else b[cnt1++] = a[j];
        }
        if (cnt2 < q) {
            ng = min(ng,a[i]);
            continue;
        }
        sort(c,c+cnt2);
        ans = min(ans,c[q-1]-c[0]);
    }
    cout << ans << endl;
}