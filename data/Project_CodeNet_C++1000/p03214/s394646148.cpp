#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    double sum = 0.0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    double ave = sum / n;
    double dist,minn = 1000000.0;
    int ans;
    for(int i=0;i<n;i++){
        dist = abs(a[i]-ave);
        if(minn>dist){
            minn = dist;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}