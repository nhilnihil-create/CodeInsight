#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(Pi a, Pi b) {
    if(a.second != b.second){
        return a.second > b.second;
        
    }else{
        return a.first < b.first;
    }
}
// 入力



int main() {
    ll D,G;

    cin >>D>>G;

    vector<ll> p(D);
    vector<ll> c(D);
    vector<Pi> pc(D);

    rep(i,D){
        cin>>p[i]>>c[i];
        //pc[i] = mp(p[i],c[i]);
    }



    ll ans = INF;
    rep(bit,1<<D){
        vector<ll> S;
        rep(i,D){
            
            if(bit & (1<<i)){
                S.pb(i);
            }
        }
        ll sum = 0;
        ll num = 0;
        vector<ll> use(D);
        rep(i,S.size()){
            sum += (S[i]+1)*p[S[i]]*100 + c[S[i]];
            num += p[S[i]];
            use[S[i]] = p[S[i]];
            
            //cout<<S[i]<<" ";
        }
        //cout<<endl;
        ll cnt = D-1;
        while(sum<G){
            if(use[cnt] <p[cnt]){
                sum+=(cnt+1)*100;
                num++;
                use[cnt]++;
                if(use[cnt] == p[cnt]){
                    sum+=c[cnt];
                }
            }else{
                cnt--;
            }
        }

        chmin(ans,num);
    }
 


    cout<<ans<<endl;


    return 0;
    

}