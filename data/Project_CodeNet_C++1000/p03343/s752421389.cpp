#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, q;
vector<int> a, p;
int f(int mn){
    vector<int> v;
    for(int i=0;i<n;i++){
        if(a[i] < mn) continue;
        int j = i+1;
        while(j < n && a[j] >= mn) j++;
        if(j-i >= k){
            vector<int> t(a.begin()+i, a.begin()+j);
            sort(t.begin(), t.end());
            for(int l=0;l<=j-i-k;l++) v.push_back(t[l]);
        }
        i = j;
    }
    int vs = v.size();
    if(vs < q) return 2e9;
    sort(v.begin(), v.end());
    return v[q-1]-mn;
}
int main(void){
    cin >> n >> k >> q;
    a.assign(n, 0);
    for(int i=0;i<n;i++) cin >> a[i];
    p.assign(n, 0);
    for(int i=0;i<n;i++) p[i] = i;
    sort(p.begin(), p.end(), [](int const& l, int const& r){ return a[l] < a[r]; } );
    int ans = 2e9;
    for(int i=0;i<n;i++){
        int tmp = f(a[p[i]]);
        if(tmp < ans) ans = tmp;
    }
    cout << ans << endl;
}
