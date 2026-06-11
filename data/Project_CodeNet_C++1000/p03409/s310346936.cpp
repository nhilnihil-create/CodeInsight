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

int main(){
    ll N;
    cin>>N;
    vector<pair<ll,ll>> a(N),b(N);
    rep(i,0,N){
        cin>>a[i].first>>a[i].second;
    }
    rep(i,0,N){
        cin>>b[i].first>>b[i].second;
    }
    sort(all(a));
    sort(all(b));
    ll ans = 0;
    rep(i,0,N){
        ll max_a = -1;
        ll ind =-1;
        rep(j,0,a.size()){
            if(a[j].first < b[i].first){
                if(a[j].second < b[i].second){
                    if(a[j].second > max_a){
                        ind = j;
                        max_a = a[j].second;
                    }
                }
            }
        }
        if(max_a != -1){
            a.erase(a.begin()+ind);
            ans++;
        }
    }
    cout<<ans;

    return 0;
}