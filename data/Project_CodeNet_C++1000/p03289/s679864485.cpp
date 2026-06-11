#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    string S;
    cin>>S;
    string ans="AC?";
    int L=sz(S);
    rep(i,L){
        if(i==0 && S.at(i)!='A'){ans="WA";}
        if(i==1){
            if(S.at(i)-'a'<0 || S.at(i)-'a'>25){ans="WA";}
        }
        if(i>=2){
            if(ans=="AC"){
                if(S.at(i)-'a'<0 || S.at(i)-'a'>25){ans="WA";}
            }
            else if(ans=="AC?"){
                if(S.at(i)-'a'<0 || S.at(i)-'a'>25){
                    if(i<L-1 && S.at(i)=='C'){ans="AC";}
                    else{ans="WA";}
                }
            }
        }
    }
    if(ans=="AC?")ans="WA";
    cout<<ans<<endl;
}