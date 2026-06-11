#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    int count = 0;
    rep(i, n) {
        if(i != n - 1) {
            if(x >= a[i]) {
                count++;
                x = x - a[i];
            }else{
                break;
            }
        }else{
            if(x==a[i])
                count++;
        }
    }
    cout << count << endl;
    return 0;
}