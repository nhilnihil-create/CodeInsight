#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
const double EPS = 1e-10;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define LCIN(n) LL(n);cin >> (n)
#define SCIN(n) string(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<LL,LL>
#define I vector<int>
#define S set<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
#define rmsame(a) sort(ALL(a)),a.erase(unique(ALL(a)), a.end())

typedef string::const_iterator State;
class PalseError {};
class Edge{
public:
    LL from,to,value;
    Edge(LL a,LL b,LL c){
        from = a;
        to = b;
        value = c;
    }
    Edge(LL a,LL b){
        from = a;
        to = b;
    }
};
int A[300000];
int B[300000];
int visit[300000];
int main(){
    CIN(N);
    CIN(M);
    SCIN(str);
    V<V<Edge>> vec(300000);
    for(int a = 0; a < M;a++){
        CIN(b);CIN(c);
        Edge e(b-1,c-1);
        Edge w(c-1,b-1);
        vec.at(b-1).push_back(e);
        vec.at(c-1).push_back(w);
    }

    queue<int> Q;
    int count = 0;
    for(int i = 1;i <= N;i++){
        for(int j = 0;j <vec.at(i-1).size();j++){
            if(str.at(vec.at(i-1).at(j).to) == 'A')A[i-1]++;
            if(str.at(vec.at(i-1).at(j).to) == 'B')B[i-1]++;
        }
        if(A[i-1] == 0||B[i-1] == 0){
            Q.push(i-1);
            visit[i-1]=1;
            count++;
        }
    }

    while(!Q.empty()){
        int t = Q.front();
        Q.pop();
        for(int i = 0;i < vec.at(t).size();i++){
            if(str.at(t) == 'A')A[vec.at(t).at(i).to]--;
            if(str.at(t) == 'B')B[vec.at(t).at(i).to]--;
            if((A[vec.at(t).at(i).to] == 0 || B[vec.at(t).at(i).to] == 0 )&& visit[vec.at(t).at(i).to] == 0){
                Q.push(vec.at(t).at(i).to);
                count++;
                visit[vec.at(t).at(i).to]=1;
            }

        }
    }
    Yes(count<N);
    return 0;
}

