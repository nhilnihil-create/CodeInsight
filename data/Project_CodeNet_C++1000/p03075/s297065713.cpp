#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main() {
    int a[5],k;

    rep(i,5)cin>>a[i];
    cin>>k;

    bool flag = true;
    rep(i,5)rep(j,i){
        if(a[i]-a[j] > k)flag = false;
    }
    if(flag == true) cout<<"Yay!"<<endl;
    else cout<<":("<<endl;

    return 0;
}