#include<bits/stdc++.h>
using namespace std;

#define p_ary(ary,a,b,i) do { cout << "["; for (int i = a;i <= b;++i) cout << ary[i] << (b == i ? "]\n" : ", "); } while(0)
#define p_map(map,it) do {cout << "{";for (auto it = map.begin();;++it) {if (it == map.end()) {cout << "}\n";break;}else cout << "" << it->first << "=>" << it->second << ", ";}}while(0)

int main() {
    int n,a[200010];

    cin >> n;
    for (int i = 0;i < n;++i) cin >> a[i];

    int min = 0,max = n,mid;
    while (max-min > 1) {
        mid = min+(max-min)/2;
        bool f = true;
        map<int,int> s;
        for (int i = 1;i < n;++i) {
            if (a[i-1] < a[i]) continue;
            if (mid == 1) {
                f = false;
                break;
            }
            s.erase(s.upper_bound(a[i]),s.end());
            //for (auto it = s.upper_bound(a[i]);it != s.end();++it) it->second = 0;
            for (int j = a[i];j > 0;--j) {
                if (s[j] < mid-1) {
                    s[j]++;
                    s.erase(s.upper_bound(j),s.end());
                    break;
                } else if (j == 1) f = false;
            }
            if (!f) break;
        }
        (f ? max : min) = mid;
    }
    cout << max << endl;
    return 0;
}