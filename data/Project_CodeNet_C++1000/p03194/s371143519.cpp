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

vector<pair<ll,ll>> prime_fact(ll x){
    ll i = 2; 
    vector<pair<ll,ll>> ans;
    while(i*i <= x){
        ll tmp = 0;
        while(x%i == 0){
            tmp++;
            x/=i;
        }
        if(tmp != 0){
            ans.push_back(make_pair(i,tmp));
        }
        i++;
    }
    if(x != 1)ans.push_back(make_pair(x,1));

    return ans;
}

int main(){
    ll N,P;
    cin>>N>>P;
    vector<pair<ll,ll>> a = prime_fact(P);
    ll ans =1;
    rep(i,0,a.size()){
        if(a[i].second >= N){
            rep(j,0,a[i].second/N){
                ans *= a[i].first;
            }
        }    
    }

    cout<<ans;
    return 0;
}