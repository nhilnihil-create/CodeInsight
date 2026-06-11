#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> c[i];
    int ans=0;
    for(int i=0;i<n;i++){
        if(v[i]-c[i]>0) ans+=v[i]-c[i];
    }
    cout << ans << endl;
}