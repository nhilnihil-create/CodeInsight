#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b;
    cin>>a>>b;
    int diff=b-a;
    int res=diff*(diff+1)/2;
    cout<<res-b<<endl;
}
