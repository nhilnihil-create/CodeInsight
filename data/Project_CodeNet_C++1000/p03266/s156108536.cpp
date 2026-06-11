#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<string>;
using P =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    ll n,k;
    cin>>n>>k;
    ll tmp=n/k;
    ll tmp1=pow(tmp,3);//tmp*tmp*tmp;
    if(k%2!=0){
        cout<<tmp1<<endl;
    }else{
        ll tmp3=pow((n+k/2)/k,3);//tmp2*tmp2*tmp2;
        cout<<tmp1+tmp3<<endl;
    }
}
