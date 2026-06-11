#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int  N,A,B;
    cin>>N>>A>>B;
    if(N*A<B)cout<<N*A<<endl;
    else cout<<B<<endl;

    return 0;
}