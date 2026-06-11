#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,sum=0,temp;
    cin>>n;
    vector<int> p(n);
    rep(i,n) {
        cin>>p[i];
        sum+=p[i];
    }
    sort(p.begin(),p.end());
    temp=p.back()/2;
    sum-=temp;
    cout<<sum<<endl;
}
