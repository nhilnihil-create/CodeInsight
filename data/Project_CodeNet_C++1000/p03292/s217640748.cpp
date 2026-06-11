#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    vector<int> a(3);
    rep(i,3) cin>>a[i];
    int sum=0;
    sort(a.begin(),a.end());
    sum+=a[2]-a[0];
    cout<<sum<<endl;
}   
