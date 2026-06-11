#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 120000;

int n;
ll a[MAXN];
vector<int> vv;
int ff[MAXN * 2];

void add(int x) {
    for(; x < 2*MAXN; x = x | (x+1) )
        ff[x]++;
}

int get(int x) {
    int ans = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
        ans += ff[x];
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vv.push_back(a[i]);
    }
    sort(vv.begin(), vv.end());
    vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
    
    // unique eleminate all duplicates (as sorted)
    // it is required to resize as size doesn't change in unique()
    
    int lb = 0;
    int rb = vv.size();
    ll all = 1LL * (n) * (n + 1) / 2;
    
    while (rb - lb > 1) {
        int mid = (lb + rb) >> 1;
        memset(ff, 0, sizeof(ff));
        int cur = n;
        add(cur);
        ll now = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= vv[mid])
                ++cur;
            else
                --cur;
            now += get(cur);
            add(cur);
        }
        if (now * 2 >= all)
            lb = mid;
        else
            rb = mid;
    }
    cout << vv[lb] << "\n";
    return 0;
}

/* using array elements only : 
as median can be one of the element of the array, mid here is index
Also, 0-indexed bit
and, binary search for l-r > 1
*/