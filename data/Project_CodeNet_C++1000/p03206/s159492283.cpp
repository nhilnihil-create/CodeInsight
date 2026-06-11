#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main() {
    int d;
    cin>>d;

    string ans;
    if(d == 25) ans = "Christmas";
    else if(d == 24) ans = "Christmas Eve";
    else if(d == 23) ans = "Christmas Eve Eve";
    else if(d == 22) ans = "Christmas Eve Eve Eve";

    cout<<ans<<endl;
        
    return 0;
}
