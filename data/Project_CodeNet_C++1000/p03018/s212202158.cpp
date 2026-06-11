//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    ll ans=0;
    vector<vector<string>> S;
    S.push_back(vector<string>(0));
    rep(i,s.size()-1){
        if(s[i]=='A'){
            S.back().push_back("A");
        }
        else if(s[i]=='B' && s[i+1]=='C'){
            S.back().push_back("BC");
            i++;
        }
        else{
            if(S.back().size()>0) 
            S.push_back(vector<string>(0));
        }
    }
    if(s.back()=='A') S.back().push_back("A");
    for(auto st:S){
        ll cnt=0;
        rep(i,st.size()){
            if(st[i]=="BC"){
                ans+=i-cnt;
                cnt++;
            }
        }
    }
    cout<<ans<<endl;
}