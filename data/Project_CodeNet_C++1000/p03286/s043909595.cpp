#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    string s;
    ll a=1;
    while (n) {
        if (n%(a*2)) {
            s+='1';
            n-=a;
        } else
            s+='0';
        a*=-2;
    }
    reverse(s.begin(),s.end());
    if (s.empty())
        s="0";
    cout<<s<<endl;
    return 0;
}