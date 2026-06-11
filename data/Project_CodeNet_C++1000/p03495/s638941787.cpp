#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    int n,k;cin>>n>>k;
    vector<int> num(n);
    rep(i,n) num.at(i)=0;
    vector<int> a(n);
    rep(i,n) cin>>a.at(i);
    rep(i,n) num[a[i]-1]++;
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    int sum=0;
    for(int i=k;i<n;i++) sum+=num[i];
    cout<<sum<<endl;
}