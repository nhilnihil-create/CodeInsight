#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
//17:23-17:25
//17:29-18:00
//9:33-10:04
const ll ALP='z'-'a'+1,MAX_Q=2e5;
ll N,Q;
string s;
char t[MAX_Q],d[MAX_Q];
bool C(ll i,ll f){
    REP(j,Q){
        if(t[j]==s[i]){
            if(d[j]=='L'){
                i--;
            }else{
                i++;
            }
            if(i<0 || i>=N){
                break;
            }
        }
    }
    if(f==0 && i<0){
        return true;
    }
    if(f==1 && i>=N){
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>Q>>s;
    REP(i,Q){
        cin.ignore();
        cin>>t[i]>>d[i];
    }
    ll ans=N;
    ll l=-1,r=N;
    while(r-l>1){
        ll m=(l+r)>>1;
        if(C(m,0)){
            l=m;
        }else{
            r=m;
        }
    }
    ans-=l+1;
    l=-1;
    r=N;
    while(r-l>1){
        ll m=(l+r)>>1;
        if(C(m,1)){
            r=m;
        }else{
            l=m;
        }
    }
    ans-=N-r;
    cout<<ans<<endl;
}
