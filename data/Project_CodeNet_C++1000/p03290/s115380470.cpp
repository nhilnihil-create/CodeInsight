#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.12f\n",(x))
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int D,G; cin >> D >> G;
    int p[15],c[15];
    rep(i,0,D) cin >> p[i] >> c[i];
    int ans = 1000000;
    rep(i,0,(1<<D)){
        int num = 0;
        ll score = 0;
        rep(j,0,D){
            if(i & (1<<j)){
                num += p[j];
                score += 100 * (j+1) * p[j] + c[j];
            }
        }
        if(score >= G){
            chmin(ans,num);
        }else{
            int pmax = 0;
            for(int j=0;j<D;j++){
                if(i & (1 << j)) continue;
                pmax = j;
            }
            if(score + 100*(pmax+1)*(p[pmax]-1) >= G){
                int t = ((G-score)+(100*(pmax+1))-1)/(100*(pmax+1));
                chmin(ans, num+t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}