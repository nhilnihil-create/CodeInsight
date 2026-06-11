#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



void func(long long N, long long M, long long Q, std::vector<long long> L, std::vector<long long> R, std::vector<long long> p, std::vector<long long> q){
    vector<vector<int> > a(N+10, vector<int>(N+10));
    for (int i = 0; i < M; ++i){
        a[L[i]][R[i]]++;
    }

    // 二次元累積和
    vector<vector<int> > s(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    for (int i = 0; i < Q; ++i) {
        lli x2 = q[i]+1;
        lli y2 = q[i]+1;
        lli x1 = p[i];
        lli y1 = p[i];
        LOG4(x1,x2,y1,y2);
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }
}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> L(M);
    std::vector<long long> R(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&L[i]);
        scanf("%lld",&R[i]);
        L[i]--,R[i]--;
    }
    std::vector<long long> p(Q);
    std::vector<long long> q(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&p[i]);
        scanf("%lld",&q[i]);
        p[i]--,q[i]--;
    }
    func(N, M, Q, std::move(L), std::move(R), std::move(p), std::move(q));
    return 0;
}
