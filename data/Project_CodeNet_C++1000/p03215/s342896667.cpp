#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)

vector<ll> pw2(51,1);
ll high_order_bit(ll n){ll tmp=1,i=-1;while(tmp<=n){tmp*=2;i++;}if(n==0) return 0;else return i;}
vector<ll> binary_expansion(ll n){vector<ll> B(41,0);ll tmp=n;for(ll i=high_order_bit(n);i>=0;i--){B[i]=tmp/pw2[i];tmp%=pw2[i];}return B;}

int main(){
	rep1(i,50) pw2[i]=2*pw2[i-1];

	ll N,K; cin>>N>>K;
	vector<ll> A(N);
    vector<ll> s(N+1,0);
    rep(i,N){
        cin>>A[i];
        s[i+1]=s[i]+A[i];
    }
    
    vector<vector<ll>> vec; 
    rep(i,N)FOR(j,i+1,N+1){
        vector<ll> V=binary_expansion(s[j]-s[i]);
        vec.pb(V);
    }

    vector<vector<ll>> tmp1(vec);//生き残り

    rrep(j,41){
        vector<vector<ll>> tmp2;

        rep(i,sz(tmp1)){
            //bitあればtmp2に入れる
            //Kコ以上残るとtmp2->tmp1
            //残らなければtmp2を空にして桁下げる

            if(tmp1[i][j]==1) tmp2.pb(tmp1[i]);
        }
        if(sz(tmp2)>=K) tmp1=tmp2;

        /*cout<<endl<<"j:"<<j<<endl;
        rep(i,sz(tmp1)){
            rep(k,41) cout<<tmp1[i][k];
            cout<<endl;
        }*/
    }

    ll ans=0;
    rrep(j,41){
        ll tmp=1; 
        rep(i,sz(tmp1)){
            tmp&=tmp1[i][j];
        }
        
        ans+=tmp*pw2[j];
    }

    cout<<ans;
}