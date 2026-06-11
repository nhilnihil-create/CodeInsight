#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    string s;
    ll k;
    cin>>s>>k;
    int cnt=0;
    while(s[cnt]==1+'0'){
        cnt++;
    }
    if((ll)cnt>=k) cout<<1<<endl;
    else{
        int ans=s[cnt]-'0';
        cout<<ans<<endl;
    }
    return 0;
}