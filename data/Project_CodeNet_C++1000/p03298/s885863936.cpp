#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
string S;

signed main(){
    cin>>N>>S;

    map<pair<string,string>,int>M;

    rep(i,1<<N){
        string s,t;
        rep(j,N){
            if(i>>j&1)s+=S[j];
            else t+=S[j];
        }
        M[pair<string,string>(s,t)]++;
    }

    int ans=0;
    rep(i,1<<N){
        string s,t;
        rep(j,N){
            if(i>>j&1)s+=S[j+N];
            else t+=S[j+N];
        }
        reverse(all(s));reverse(all(t));
        ans+=M[pair<string,string>(t,s)];
    }
    cout<<ans<<endl;
    return 0;
}
