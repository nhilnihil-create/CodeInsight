#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N,K;
double ans=0.0;

int ipow(int x,int n){
    int ret=1;
    for(int i=0;i<n;++i)ret*=x;
    return ret;
}

signed main(){
    cin>>N>>K;
    for(int D=1;D<=N;++D){
        double d=(double)K/(double)D;
        int n=ceil(log2(d));
        //if(n<0)continue;
        double p=(double)((1.0/(double)(N))/(double)(ipow(2,n)));
        //cout<<p<<endl;
        ans+=p;
    }
    printf("%.15f\n",ans);
}