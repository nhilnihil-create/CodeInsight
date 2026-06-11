#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int n; sc(n)
    vector<int> a(n);
    for (int i = 0; i < n; i++) sc(a[i])
    for (int i = 0; i < n; i++) a[i] = a[i] - (i+1);
    sort(a.begin(), a.end());
    ll ans = 0, b, mid = a.size()/2;
    if (a.size() % 2 == 0){
        b = (a[mid] + a[mid-1]) / 2;
        if ((a[mid] + a[mid-1]) % 2 != 0){
            if (a[mid] + a[mid-1] > 0) b += 1;
            else b -= 1;
        }
    }else b = a[mid];
    for (int i = 0; i < n; i++) ans += abs(a[i] - b);
    cout << ans << endl;
    return 0;
}