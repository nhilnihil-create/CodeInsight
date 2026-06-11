#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    ll X[N], Y[N];
    rep(i,0,N) cin >>X[i]>>Y[i];
    ll k=((X[0]+Y[0])%2+2)%2;
    rep(i,0,N){
        if(((X[i]+Y[i])%2+2)%2!=k){
            cout <<-1<<"\n";
            return 0;
        }
    }
    if(k){
        cout <<40<<"\n";
        rep(i,0,40){
            if(i==39) cout <<(ll(1)<<i)<<"\n";
            else cout <<(ll(1)<<i)<<" ";
        }
        vector<char> ans;
        rep(i,0,N){
            rer(j,40,0){
                if(Y[i]>=X[i]&&Y[i]>=-X[i]){
                    ans.pb('U');
                    Y[i]-=(ll(1)<<j);
                }
                else if(Y[i]>=X[i]&&Y[i]<=-X[i]){
                    ans.pb('L');
                    X[i]+=(ll(1)<<j);
                }
                else if(Y[i]<=X[i]&&Y[i]>=-X[i]){
                    ans.pb('R');
                    X[i]-=(ll(1)<<j);
                }
                else if(Y[i]<=X[i]&&Y[i]<=-X[i]){
                    ans.pb('D');
                    Y[i]+=(ll(1)<<j);
                }
            }
            rev(ans);
            rep(j,0,40){
                cout <<ans[j];
            }
            cout <<"\n";
        }
    }
    else{
        cout <<40<<"\n";
        cout <<1<<" ";
        rep(i,0,39){
            if(i==38) cout <<(ll(1)<<i)<<"\n";
            else cout <<(ll(1)<<i)<<" ";
        }
        vector<char> ans;
        rep(i,0,N){
            X[i]--;
            rer(j,39,0){
                if(Y[i]>=X[i]&&Y[i]>=-X[i]){
                    ans.pb('U');
                    Y[i]-=(ll(1)<<j);
                }
                else if(Y[i]>=X[i]&&Y[i]<=-X[i]){
                    ans.pb('L');
                    X[i]+=(ll(1)<<j);
                }
                else if(Y[i]<=X[i]&&Y[i]>=-X[i]){
                    ans.pb('R');
                    X[i]-=(ll(1)<<j);
                }
                else if(Y[i]<=X[i]&&Y[i]<=-X[i]){
                    ans.pb('D');
                    Y[i]+=(ll(1)<<j);
                }
            }
            ans.pb('R');
            rev(ans);
            rep(j,0,40){
                cout <<ans[j];
            }
            cout <<"\n";
        }
    }
}