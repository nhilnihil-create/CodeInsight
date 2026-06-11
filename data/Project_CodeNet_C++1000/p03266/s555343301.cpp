#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using graph=vector<vector<int>>;
using field=vector<string>;
using p =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    ll n,k;
    cin>>n>>k;
    if(k%2!=0){
        ll tmp1=pow(n/k,3);//tmp*tmp*tmp;
        cout<<tmp1<<endl;
    }else{
        ll tmp1=pow(n/k,3);//tmp*tmp*tmp;
        ll tmp3=pow((n+k/2)/k,3);//tmp2*tmp2*tmp2;
        cout<<tmp1+tmp3<<endl;
    }
}