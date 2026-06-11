
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
bool is_prime(int n){
    bool flag=true;
    if(n==1)flag=false;
    else if(n==2)flag=true;
    else{
      FOR(i,2,sqrt(n)+1){
        if(n%i==0)flag=false;
      }
    }
    return flag;
}
int main(){
  int n;cin>>n;
  vector<pair<int,int>> v;
  rep(i,n){
    int a,b;cin>>a>>b;
    v.push_back(make_pair(a,b));
  } 
  vector<int> che(100001);
  che[0]=0;
  rep(i,100000){
    if(is_prime(i+1)&&is_prime((i+2)/2))che[i+1]=che[i]+1;
    else che[i+1]=che[i];
  }
  //rep(i,100)cout<<che[i]<<endl;
  rep(i,n){
    cout<<che[v[i].S]-che[v[i].F-1]<<endl;
  }
}