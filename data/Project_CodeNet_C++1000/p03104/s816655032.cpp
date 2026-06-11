//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll a,b; cin>>a>>b;
    a--;
    ll numa=(a+1)/2;
    if(a%2==0){
        if(numa%2==0)numa=a^0;
        else numa=a^1;
    }
    else{
          if(numa%2==0)numa=0;
        else numa=1;
    }
    ll numb=(b+1)/2;
    if(b%2==0){
        if(numb%2==0)numb=b^0;
        else numb=b^1;
    }
    else{
          if(numb%2==0)numb=0;
        else numb=1;
    }
    //cout<<numa<<endl;
    //cout<<numb<<endl;
    ll ans=numa^numb;
    cout<<ans<<endl;


}









