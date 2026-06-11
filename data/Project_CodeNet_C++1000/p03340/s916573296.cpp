#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const long long INF = 1LL<<60;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max


int main () {

    int n;cin>>n;

    int a[200010];

    rep(i,n) {
        cin>>a[i];
    }

    ll ans=0;
    int right=0;
    int sum=0,sum_x=0;
    for (int left=0;left<n;left++) {
        while(right<n&&(sum+a[right]==(sum_x ^ a[right]))) {
            sum+=a[right];
            sum_x ^=a[right];
            right++;
        }
        ans+=right-left;
        if (right==left) {
            right++;
        }
        else {
            sum-=a[left];
            sum_x^=a[left];
        }
    }

    cout<<ans<<endl;
}