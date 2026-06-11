#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    vector<int> sorted_x = x;
    sort(ALL(sorted_x));
    int mid = sorted_x[n/2-1];
    for(int i = 0; i <= n-1; ++i){
        if(x[i] <= mid) cout << sorted_x[n/2] << endl;
        else cout << mid << endl;
    }
    return 0;
}