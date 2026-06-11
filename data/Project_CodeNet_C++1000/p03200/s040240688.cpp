#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    string s;cin>>s;
    ll countb = 0;
    ll ans = 0;
    int n = s.size();
    for(int i = 0;i<n;++i){
        if(s[i]=='W') {
            ans+=countb;
        }

        else {
            countb++;
        }

    }
    cout<<ans<<endl;

}
