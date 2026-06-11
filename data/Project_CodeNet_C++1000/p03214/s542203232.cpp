#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
    int N, ans;
    cin >> N;
    int a[N];
    double ave;
    double sum = 0.0;
    rep(i, N) {
        cin >> a[i];
        sum += a[i];
    }
    
    ave = sum / N;

    double distance = 0.0, tmp = 100.0;

    rep(i, N) {
        distance = fabs(ave - a[i]);

        if(distance < tmp) {
            ans = i;
            tmp = distance;
        }
    }

    cout << ans << endl;

    return 0;
}