#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    
    rep(i,n)cin >> a[i];

    sort(a.begin(),a.end());

    vector<int> b(n);

    rep(i,n){
        b[i]=min(x,a[i]);
        x-=b[i];

    }
    b.back()+=x;

    int ans = 0;

    rep(i,n){
        ans+=(a[i]==b[i]);
    }

    cout << ans << endl;

}