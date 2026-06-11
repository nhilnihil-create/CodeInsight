#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n+1);
    b[0]=0;
    for(int i = 0; i < n; i++) {
        b[i+1]=a[i]+b[i];
    }

//    for(int i = 0; i <= n; i++) {
//        cout << b[i] << " ";
//    }

    sort(b.begin(),b.end());
    map<int,int> cnt;
    for(int i = 0; i <= n; i++) {
        cnt[b[i]]++;
    }
    int ans=0;
    for(auto itr = cnt.begin(); itr !=cnt.end(); itr++) {
        int tmp=itr->second;
        ans+=tmp*(tmp-1)/2;
    }
    cout << ans << "\n";

    return 0;
}