#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,k;cin>>n>>k;
    pair<int,int> a[n];
    for (int i=0;i<n;i++) {
        int b,c;cin>>b>>c;
        b--;
        a[i]={c,b};
    }
    sort(a,a+n,greater<pair<int,int>>());
    int used[n]{};
    stack<int> dup;
    ll sum=0;
    ll c=0;
    for (int i=0;i<k;i++) {
        sum+=a[i].first;
        if (used[a[i].second])
            dup.push(a[i].first);
        else {
            used[a[i].second]=1;
            c++;
        }
    }
    ll mx=sum+c*c;
    for (int i=k;i<n&&dup.size();i++)
        if (!used[a[i].second]) {
            sum-=dup.top();
            dup.pop();
            sum+=a[i].first;
            used[a[i].second]=1;
            c++;
            mx=max(mx,sum+c*c);
        }
    cout<<mx<<endl;
    return 0;
}