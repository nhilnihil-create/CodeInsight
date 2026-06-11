#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 1e18
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

vector<long long> LISLDS(long long N, long long A, long long B) {
    vector<long long> res;
    for (long long i = B-1; i >= 0; --i) res.push_back(i);
    
    if (A == 1) return res;
    
    long long rem = N - B;
    long long p = rem / (A-1);
    long long r = rem % (A-1);
    
    long long b = r;
    long long c = A-1-r;
    
    for (int i = 0; i < b; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p+1; ++j) {
            res.push_back(size + p - j);
        }
    }
    for (int i = 0; i < c; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p; ++j) {
            res.push_back(size + p-1 - j);
        }
    }
    
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,A,B;
    cin>>N>>A>>B;
    if(A+B>N+1 || A*B<N) cout<<-1<<endl;
    else{
        auto res = LISLDS(N,A,B);
        for(auto x:res){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }

}