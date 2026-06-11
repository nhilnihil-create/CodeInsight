#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,k;cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;i+j<=min(n,k);j++) {
            int sum=0;
            priority_queue<int> q;
            for (int l=0;l<i;l++) {
                sum+=a[l];
                q.push(-a[l]);
            }
            for (int l=n-1;l>n-1-j;l--) {
                sum+=a[l];
                q.push(-a[l]);
            }
            int l=0;
            while (q.size()&&q.top()>0&&l<k-j-i) {
                sum+=q.top();
                q.pop();
                l++;
            }
            ans=max(ans,sum);
        }
    cout<<ans<<endl;
    return 0;
}