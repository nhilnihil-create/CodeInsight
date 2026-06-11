#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct lr{
    int l,r;
    bool operator<(const lr& a) const{
        if(r!=a.r)return r<a.r;
        else return l < a.l;
        
    }
};

int main(){
    ll N,M;
    cin>>N>>M;

    vector<lr> lis(M);
    rep(i,0,M){
        int a,b;
        cin>>a>>b;
        lr tmp;
        tmp.l = a;
        tmp.r = b;
        lis[i] = tmp;
    }
    sort(all(lis));
    ll ans = 1;
    int rmin = INF;
    rep(i,0,M){
        if(rmin <=lis[i].l){
            rmin = lis[i].r;
            ans++;
        }
        else{
            rmin= min(rmin,lis[i].r);
        }
    }
    cout<<ans;
    return 0;
}