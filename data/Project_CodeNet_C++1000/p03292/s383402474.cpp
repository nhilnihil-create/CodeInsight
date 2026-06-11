#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    vector<int> a(3);

    rep(i,3)    cin >> a[i];
    sort(a.begin(),a.end());

    cout << a[2]-a[0] << endl;

    return 0;
}