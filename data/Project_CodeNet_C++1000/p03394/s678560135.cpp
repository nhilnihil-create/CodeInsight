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

const int MAX_S = 300015000;

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin>>N;
    set<int> ans;
    if (N==3){
        cout<<"2 5 63\n";
        return 0;
    }
    if (N>=15000){
        FOR(i,1,30000)
            if (i%2==0||i%3==0) ans.ins(i);
        int rm = 20000-N;
        FOR(i,1,rm){
            ans.erase(i*6);
        }
        bool first=true;
        for(auto e:ans){
            if (!first) cout<<" ";
            else first=false;
            cout<<e;
        }cout<<"\n";
        return 0;
    }
    int sum=0;
    FOR(i,7,30000){
        if (i%2==0||i%3==0) ans.ins(i), sum+=i;
        if (ans.size()==N-2) break;
    }
    int t = sum%6;
    if (t==0) ans.ins(2), ans.ins(4);
    if (t==1) ans.ins(2), ans.ins(3);
    if (t==2) ans.ins(4), ans.ins(6);
    if (t==3) ans.ins(3), ans.ins(6);
    if (t==4) ans.ins(2), ans.ins(6);
    if (t==5) ans.ins(3), ans.ins(4);
    bool first=true;
    for(auto e:ans){
        if (!first) cout<<" ";
        else first=false;
        cout<<e;
    }cout<<"\n";
    return 0;
}
