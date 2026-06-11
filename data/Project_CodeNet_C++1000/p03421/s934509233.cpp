#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    if (A+B-1>N){
        cout << -1 << endl;
        return 0;
    }
    if (A==1){
        if (B!=N){
            cout << -1 << endl;
            return 0;
        }
        for (int i=N;i>0;--i) cout << i << ' ';
        cout << endl;
        return 0;
    }
    if (B==1){
        if (A!=N){
            cout << -1 << endl;
            return 0;
        }
        for (int i=1;i<=N;++i) cout << i << ' ';
        cout << endl;
        return 0;
    }
    if ((N+A-1)/A<=B){
        int x=(N-B)/(A-1),y=(N-B)%(A-1)+1,now=N-A+1;
        rep(i,x){
            rep(j,A){
                cout << now+j << ' ';
            }
            if (i!=x-1) now-=A;
            else now-=y;
        }
        if (now<=0) return 0;
        rep(i,y) cout << now+i << ' ';
        --now;
        while(now>0){
            cout << now << ' ';
            --now;
        }
        cout << endl;
        return 0;
    }
    if ((N+B-1)/B<=A){
        int x=(N-A)/(B-1),y=(N-A)%(B-1)+1,now=B;
        rep(i,x){
            rep(j,B){
                cout << now-j << ' ';
            }
            if (i!=x-1) now+=B;
            else now+=y;
        }
        if (now>=N+1) return 0;
        rep(i,y) cout << now-i << ' ';
        ++now;
        while(now<=N){
            cout << now << ' ';
            ++now;
        }
        cout << endl;
    }
    else cout << -1 << endl;
}