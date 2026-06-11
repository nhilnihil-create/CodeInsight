#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i <= n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    vec l(1000005,INF);
    int n;
    cin>> n;
    l[0]=0;
    l[1]=1;
    reps(i,2,n){
        l[i]=l[i-1]+1;
        int a=6;int b=9;
        while(a<=i){
            l[i]=min(l[i-a]+1,l[i]);
            a*=6;
        }
        while(b<=i){
            l[i]=min(l[i-b]+1,l[i]);
            b*=9;
        }
    }
    cout<<l[n]<<endl;
    return 0;
}