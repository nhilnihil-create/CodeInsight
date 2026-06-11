#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main() {
    vector<int> a(6);
    rep(i,6) {
        cin>>a[i];
    }
    string ans="Yay!";
    rep(i,5) {
        for (int j=i+1; j<5; j++) {
            if (a[j]-a[i]>a[5]) {
                cout<<":("<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}