#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N;
    cin >>N;
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    vector<bool>br;
    vector<bool> ans;
    ll M=abs(N);
 
    while(M){
        br.pb(M%2);
        M/=2;
    }
    br.pb(0);
    br.pb(0);
    bool flag=0;
    if(N>0){
        rep(i,br.size()){
            
            if(br[i]==1){
                if(i%2==0){
                    if(flag){
                        ans.pb(0);
                        //cout<<'a'<<endl;
                    }else{
                        ans.pb(1);
                        //cout<<'b'<<endl;
                    }
                }else{
                    if(flag){
                        ans.pb(0);
                        //cout<<'c'<<endl;
                    }else{
                        ans.pb(1);
                        flag = 1;
                        //cout<<'d'<<endl;
                    }
                }
            }else{
                if(flag){
                    if(i%2==0){
                        ans.pb(1);
                        flag = 0;
                        //cout<<'e'<<endl;
                    }else{
                        ans.pb(1);
                        //cout<<'f'<<endl;
                    }
                }else{
                    ans.pb(0);
                    //cout<<'g'<<endl;
                }
                

            }
        }
    }else{
        rep(i,br.size()){
            
            if(br[i]==1){
                if(i%2==1){
                    if(flag){
                        ans.pb(0);
                        //cout<<'a'<<endl;
                    }else{
                        ans.pb(1);
                        //cout<<'b'<<endl;
                    }
                }else{
                    if(flag){
                        ans.pb(0);
                        //cout<<'c'<<endl;
                    }else{
                        ans.pb(1);
                        flag = 1;
                        //cout<<'d'<<endl;
                    }
                }
            }else{
                if(flag){
                    if(i%2==1){
                        ans.pb(1);
                        flag = 0;
                        //cout<<'e'<<endl;
                    }else{
                        ans.pb(1);
                        //cout<<'f'<<endl;
                    }
                }else{
                    ans.pb(0);
                    //cout<<'g'<<endl;
                }
                

            }
        }
    }
    reverse(all(ans));
    ll st=0;
    rep(i,ans.size()){
        if(ans[i]==1){
            st=1;
        }
        if(st==1){
            cout<<ans[i];
        }
        
    }
    
    cout<< endl;


    return 0;
    

}