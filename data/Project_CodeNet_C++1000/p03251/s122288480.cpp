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


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void YN(bool ans){
    if(ans)cout<<"No War"<<endl;
    else cout <<"War"<<endl;
    return;
}
int main(){
    ll N,M,X,Y;
    cin>>N>>M>>X>>Y;
    v x(N),y(M);
    ll min_x = X, min_y = Y;
    rep(i,0,N){
        cin>>x[i];
        min_x = max (min_x, x[i]);
    }
    rep(i,0,M){
        cin>>y[i];
        min_y = min (min_y, y[i]);
    }

    YN(min_x< min_y);
    return 0;
}