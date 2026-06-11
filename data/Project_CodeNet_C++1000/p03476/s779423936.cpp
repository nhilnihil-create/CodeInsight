#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 1001001001;
const double EPS = 1e-10;
struct Edge { ll from, to, cost; };
using Graph = vector<vector<Edge>>;

bool is_prime[101010];

void eratos(int x){
    fill(is_prime,is_prime+101010,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=x;i++){
        if(!is_prime[i])continue;
        for(int j=2*i;j<=x;j+=i)is_prime[j]=false;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    eratos(101010);
    int c_sum[101010]={};
    for(int x=1;x<101010;x++){
        if(x%2==0){
            c_sum[x]=c_sum[x-1];
            continue;
        }
        int y=(x+1)/2;
        if(is_prime[x]&&is_prime[y])c_sum[x]=(x>1?c_sum[x-2]:0)+1;
        else c_sum[x]=(x>1?c_sum[x-2]:0);
    }
    int q;
    cin>>q;
    for(int i=0,l,r;i<q;i++){
        cin>>l>>r;
        cout<<c_sum[r]-c_sum[l-1]<<endl;
    }
}