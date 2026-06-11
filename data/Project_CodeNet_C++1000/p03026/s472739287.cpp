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

lli cnt[10010];
bool vis[10010];
vector<lli> G[10010];

void func(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c){

    sort(c.rbegin(),c.rend());

    vector<lli> ans(N);

    lli startIndex;
    lli startC = 0;
    lli sum = 0;
    REP(i,0,N){
        if(startC<cnt[i]){
            startIndex = i;
            startC = cnt[i];
        }
    }

    vis[startIndex]=true;
    queue<lli> q;
    q.push(startIndex);
    lli num = 0;

    while(q.size()){
        lli top = q.front();
        q.pop();
        ans[top] = c[num];
        num++;
        for(auto e:G[top]){
            if(vis[e])continue;
            vis[e]=true;
            q.push(e);
        }
    }
    REP(i,0,N)sum+=c[i];
    sum -= c[0];

    cout<<sum<<endl;
    REP(i,0,ans.size())cout<<ans[i]<<" ";
    cout<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        a[i]--,b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    std::vector<long long> c(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&c[i]);
    }
    func(N, std::move(a), std::move(b), std::move(c));
    return 0;
}
