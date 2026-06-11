#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s;cin >> s;
    int n = s.size();
    ll ans = 0;
    ll sequenceAcount=0;
    for(int i=0;i<n-3+1;){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
            ++ans;
            s[i] = 'B';
            s[i+1] = 'C';
            s[i+2] = 'A';
            if(sequenceAcount>0){
                ans += sequenceAcount;
            }
            i += 2;
        }else if(s[i]=='A'){
            ++sequenceAcount;
            ++i;
        }else{
            sequenceAcount = 0;
            ++i;
        }
    }
    cout << ans << endl;
}