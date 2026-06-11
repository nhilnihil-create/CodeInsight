#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin>>A>>B>>C;
    if (A == B) cout<<C<<endl;
    else if (B == C) cout<<A<<endl;
    else cout<<B<<endl;
}