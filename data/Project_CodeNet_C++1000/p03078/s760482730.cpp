#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    vector<ll> v;
    rep(i,X){
        cin >> A[i];
        //v.emplace_back(A[i],0);
    }
    sort(A.rbegin(), A.rend());
    rep(i,Y){
        cin >> B[i];
        //v.emplace_back(B[i],1);
    }
    sort(B.rbegin(), B.rend());
    rep(i,Z){
        cin >> C[i];
        //v.emplace_back(C[i],2);
    }
    sort(C.rbegin(), C.rend());
    priority_queue<pair<Pll,Pll>> que;
    map<PlP,ll> mp;
    ll a = 0;
    ll b = 0;
    ll c = 0;
    mp[PlP(a,Pll(b,c))]++;
    que.push(make_pair(Pll(A[a]+B[b]+C[c], a), Pll(b,c)));
    rep(qqq, K){
        a = que.top().first.second;
        b = que.top().second.first;
        c = que.top().second.second;
        v.push_back(que.top().fi.fi);
        que.pop();
        if(a < X-1 && mp[PlP(a+1,Pll(b,c))] == 0){
            mp[PlP(a+1,Pll(b,c))]++;
            que.push(make_pair(Pll(A[a+1]+B[b]+C[c], a+1), Pll(b,c)));
        }
        if(b < Y-1 && mp[PlP(a,Pll(b+1,c))] == 0){
            mp[PlP(a,Pll(b+1,c))]++;
            que.push(make_pair(Pll(A[a]+B[b+1]+C[c], a), Pll(b+1,c)));
        }
        if(c < Z-1 && mp[PlP(a,Pll(b,c+1))] == 0){
            mp[PlP(a,Pll(b,c+1))]++;
            que.push(make_pair(Pll(A[a]+B[b]+C[c+1], a), Pll(b,c+1)));
        }
    }
    rep(i,K){
        cout << v[i] << endl;
    }
    //sort(v.rbegin(), v.rend());
    /*
    ll a = 0;
    ll b = 0;
    ll c = 0;
    v.push_back(A[a]+B[b]+C[c]);
    rep(t,K-1){
        ll AA = 0;
        ll BB = 0;
        ll CC = 0;
        if(a < X - 1){
            AA = A[a+1]+B[b]+C[c];
        }else{
            AA = 
        }
        if(b < Y - 1)BB = A[a]+B[b+1]+C[c];
        if(c < Z - 1)CC = A[a]+B[b]+C[c+1];
        if(AA >= BB && AA >= CC){
            v.push_back(AA);
            a++;
        }else if(BB >= AA && BB >= CC){
            v.push_back(BB);
            b++;
        }else{
            v.push_back(CC);
            c++;
        }
    }
    rep(i,K){
        cout << v[i] << endl;
    }
    /*multiset<ll> ms;
    rep(i,X){
        rep(j,Y){
            ms.insert(A[i]*B[j]);
        }
    }*/
}