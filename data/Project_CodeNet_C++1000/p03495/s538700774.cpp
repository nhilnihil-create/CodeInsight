#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,k;
    cin >> n >> k;
    map<int,int> a;
    vector<int> b;
    rep(i,n){
        int b;
        cin >> b;
        a[b]++;
    }
    for(auto i:a) b.push_back(i.second);
    sort(b.begin(),b.end());
    int j = 0,ans = 0;
    rep(i,(int)b.size()-k) ans += b[i];
    cout << ans << endl;
}