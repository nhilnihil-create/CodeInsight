#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    vector<ll> plus_val,minus_val;
    vector<bool> flag_plus,flag_minus;
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)a[i]-=b[i];
    ll ans=0;int p,q;p=0;q=0;
    rep(i,n){
        if(a[i]>0){
            plus_val.push_back(a[i]);
            flag_plus.push_back(false);
        }else if(a[i]<0){
            minus_val.push_back(a[i]);
            flag_minus.push_back(false);
        }
    }
    if(!minus_val.empty()){
        ssort(minus_val);
    }else{
        cout << 0 << endl;
        return 0;
    }
    if(!plus_val.empty())rsort(plus_val);

    while(p<plus_val.size()&&q<minus_val.size()){
        if(abs(plus_val[p])==abs(minus_val[q])){
            flag_plus[p]=true;flag_minus[q]=true;
            p++;q++;
        }else if(abs(plus_val[p])<abs(minus_val[q])){
            flag_plus[p]=true;flag_minus[q]=true;
            minus_val[q]+=plus_val[p];
            p++;
        }else{
            flag_plus[p]=true;flag_minus[q]=true;
            plus_val[p]+=minus_val[q];
            q++;
        }
    }
    if(q==minus_val.size()){
        rep(i,plus_val.size()){
            if(flag_plus[i]==true){
                ans++;
            }
        }
        rep(i,minus_val.size()){
            if(flag_minus[i]==true){
                ans++;
            }
        }
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }

}