#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=1e18;

vector<ll> prime(){
    vector<ll> res;
    vector<bool> is_prime(55556,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=55555;i++){
        if(!is_prime[i]) continue;
        for(int j=i*2;j<=55555;j+=i) is_prime[j]=false;
    }
    for(int i=0;i<=55555;i++){
        if(is_prime[i]) res.push_back(i);
    }
    return res;
}
int main(){
    int n;cin>>n;
    vector<ll> res=prime(),ans;
    for(auto it:res)if(it%5==2) ans.push_back(it);
    for(int i=0;i<n;i++){
        cout<<ans[i];
        if(i<n-1) cout<<' ';
    }
    cout<<endl;
    return 0;
}