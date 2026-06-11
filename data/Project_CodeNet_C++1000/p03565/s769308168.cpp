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
#define mp make_pair
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second > b.second;
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
    string S,T;
    cin>>S>>T;
    
    ll SN = S.size();
    ll TN = T.size();
    string CS = S;
    vector<string> ans;
    rep(i,SN -TN+1){
        S=CS;
        rep(j,TN){
            if(S[i+j] != T[j] && S[i+j]!='?'){
                break;
            }else{
                S[i+j] = T[j];
            }
            if(j==TN-1){
                ans.pb(S);
            }
        }
    }

    if(ans.size() != 0){
        rep(i,ans.size()){
            rep(j,SN){
                if(ans[i][j] == '?'){
                    ans[i][j] = 'a';
                }
            }
        }
        sort(all(ans));
        cout<<ans[0]<<endl;
    }else{
        cout<<"UNRESTORABLE"<<endl;
    }
    return 0;
    

}