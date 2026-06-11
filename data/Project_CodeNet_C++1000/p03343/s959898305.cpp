#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int N,K,Q,A[2020];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>K>>Q;
    REP(i,N) cin>>A[i];

    int ans = INF;
    REP(y,N){
        int Y = A[y];
        
        vector<int> v;
        v.push_back(-1);
        REP(i,N) if(A[i]<Y) v.push_back(i);
        v.push_back(N);

        int n = v.size();
        priority_queue<int,vector<int>,greater<int>> qu;

        REP(i,n-1){
            int l = v[i] + 1;
            int r = v[i+1];

            priority_queue<int,vector<int>,greater<int>> buf;
            for(int i=l;i<r;i++) buf.push(A[i]);
            while(K<=buf.size()){
                qu.push(buf.top());
                buf.pop();
            }
        }
        int X = Y;
        int q = Q;
        while(0<q && !qu.empty()){
            chmax(X,qu.top());
            qu.pop();
            q--;
        }
        if(q==0) chmin(ans,X-Y);
    }
    cout<<ans<<endl;
}
