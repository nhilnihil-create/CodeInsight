#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    ll ans = 0;
    ll sum = 0;
    int right = 0;
    for(int left = 0; left < N; left++){
        while(right < N && ((sum ^ a[right]) == (sum + a[right]))){
            sum += a[right];
            right++;
        }

        ans += (right - left);

        if(right == left) right++;
        else sum -= a[left];
    }
    cout << ans << endl;
    return 0;
}