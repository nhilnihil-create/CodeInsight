#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin>>S;
    int N = S.size();
    auto check = [&](){
        if (S[0]=='0'||S[N-1]=='1') return false;
        rep(i,N/2)if(S[i]!=S[N-i-2]){
            return false;
        }
        return true;
    };
    if (!check()){
        cout<<"-1\n";
        return 0;
    }
    int cur=1;
    rep(i,N/2){
        cout<<cur<<" "<<i+2<<"\n";
        if (S[i]=='1') cur=i+2;
    }
    rep(i,N-N/2-1){
        cout<<cur<<" "<<N-i<<"\n";
    }
    return 0;
}
