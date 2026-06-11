#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main() {
    char s,ans;
    cin>>s;
    if (s=='A') ans='T';
    else if(s=='C') ans='G';
    else if(s=='G') ans='C';
    else ans='A';
    cout<<ans<<endl;
}