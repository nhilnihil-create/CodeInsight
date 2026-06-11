#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    string s;
    int p;
    tuple<string,int,int>x[n];
    rep(i,n){
        cin>>s>>p;
        x[i]=make_tuple(s,-p,i+1);
    }
    sort(x,x+n);
    rep(i,n){
        cout<<get<2>(x[i])<<endl;
    }

    return 0;
}
