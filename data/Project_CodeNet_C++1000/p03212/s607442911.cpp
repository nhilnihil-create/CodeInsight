#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<char>>;
using P =pair<int,int>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const ll mod=1000000007;

ll n;
ll ans=0;

void check(ll x){
    if(x>n)return;
    int cnt[3]={};
    while(x){
        if(x%10==3)cnt[0]++;
        if(x%10==5)cnt[1]++;
        if(x%10==7)cnt[2]++;
        x/=10;
    }
    if(cnt[0]>0&&cnt[1]>0&&cnt[2]>0)++ans;
}
void dfs(ll x){
    check(x);
    if(x<=1000000000){
        dfs(10*x+3);
        dfs(10*x+5);
        dfs(10*x+7);
    }
}


int main(){
    cin>>n;
    dfs(0);
    cout<<ans<<endl;

    return 0;
}
