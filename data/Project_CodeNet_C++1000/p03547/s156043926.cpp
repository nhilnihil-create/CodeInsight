#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string a,b;
    cin>>a>>b;
    if (a>b) cout<<'>'<<endl;
    else if(a==b) cout<<'='<<endl;
    else cout<<'<'<<endl;
}
