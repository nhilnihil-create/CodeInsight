#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int,int> vmp;
    for(int i = 0; i < n; i++) {
        int tmp=a[i];
        vmp[tmp]++;
    }
    vector<pair<int,int>> vp;
    for(auto itr = vmp.begin(); itr != vmp.end(); itr++) {
        vp.emplace_back(itr->second,itr->first);
    }
    sort(vp.begin(),vp.end());
    int count=0;
    int il=max(vp.size()-k,(unsigned long)0);
    for(int i = 0; i < il; i++) {
        count+=vp[i].first;
    }
    cout << count << "\n";
    return 0;
}