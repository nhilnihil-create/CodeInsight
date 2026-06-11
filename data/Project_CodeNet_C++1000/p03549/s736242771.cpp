#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,m;
    cin>>n>>m;
    int ans=100*(n-m);
    ans+=1900*m;
    int k=pow(2,m);
    cout<<ans*k<<endl;
}   
