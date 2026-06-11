#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, M;
    cin>>n>>M;
    map<int, int> cnt;

    int sum = 0;
    cnt[sum]++;

    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;
        sum = (sum+x)%M;
        cnt[sum]++;
    }

    long long ans = 0;
    for (auto pr: cnt)  ans += 1LL*pr.second*(pr.second-1)/2;
    cout<<ans<<endl;
}
