#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
    int n,a,b,diff;
    cin>>n>>a>>b;
    diff=b-a;
    if(diff%2==0) cout<<"Alice"<<endl;
    else cout<<"Borys"<<endl;
}
