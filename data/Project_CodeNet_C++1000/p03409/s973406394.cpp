#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }

#define pii pair<int,int>

bool func1(pii a,pii b){
    return a.first<b.first;
}
bool func2(pii a,pii b){
    return a.second>b.second;
}

int main(){
    int N; cin>>N;
    vector<pii> r(N),b(N);
    
    REP(i,N){
        int x,y; cin>>x>>y;
        r[i] = make_pair(x,y);
    }
    REP(i,N){
        int x,y; cin>>x>>y;
        b[i] = make_pair(x,y);
    }
    sort(ALL(r),func2);
    sort(ALL(b),func1);
    int ans = 0;
    for(pii p:b){
        vector<pii>::iterator itr = r.begin();
        while(itr != r.end()){
            pii q = *itr;
            if(p.first>q.first && p.second>q.second){
                ++ans;
                r.erase(itr);
                break;
            }
            ++itr;
        }
    }
    cout << ans <<"\n";
}