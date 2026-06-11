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
    if(ans)cout<<"Yes"<<endl;
    else cout <<"No"<<endl;
    return;
}
int main(){
    ll N;
    cin>>N;
    v a(N),b(N);
    rep(i,0,N){
        cin>>a[i];
    }
    rep(i,0,N){
        cin>>b[i];
    }
    ll plus = 0, minus = 0;
    rep(i,0,N){
        if(a[i] <= b[i])plus += (b[i]-a[i])/2;
        else minus += a[i]-b[i];
    }
    YN(plus >= minus);

    return 0;
}