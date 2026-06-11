#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<int(n);i++)

int main(){
    string S;
    cin>>S;
    int ans=700;
    rep(i,3) {
        if (S.at(i)=='o') {
            ans+=100;
        }
    }
    cout<<ans<<endl;
}
