#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n;cin >> n;
    ll sum=0;
    int minus=0;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]<0) minus++;
        b[i]=abs(a[i]);
        sum += b[i];
    }
    sort(b.begin(),b.end());

    if(minus%2==0) cout << sum << endl;
    else cout << sum-2*b[0] << endl;

    return 0;
}