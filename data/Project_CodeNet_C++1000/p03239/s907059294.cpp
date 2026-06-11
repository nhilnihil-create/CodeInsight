#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){  if(b==0){  return a; }   return gcd(b , a%b); }


void solve(int a[],int n){
  int flag = 0;
  for(int i=0;i<n-1;i++){
    if(a[i+1]-a[i] > 1 ){
      cout<<"NO\n";
      flag = 1;
      break;
    }
  }

  if(!flag){
    cout<<"YES\n";
  }
  
}

ll min(ll a , ll b){   if (a > b){    return b; }  return a; }

ll freq_elem(unordered_map<ll,ll> umap){

ll num , freq_elem = 0;

for( auto i: umap){
  if(i.second > freq_elem){
    freq_elem = i.second;
    num = i.first;
  }
}


return freq_elem;
}

int main(){


int n,t;
cin>>n>>t;
vector<pair<int,int>> vect;
REP(i,n){
  int c,time;
  cin>>c>>time;  
  if(time <= t){
     vect.push_back({c, time});
  }
}

sort(vect.begin(),vect.end());

// REP(i,vect.size()){
//   cout<<vect[i].first<<" =>"<<vect[i].second<<"\n";
// }

if(vect.size() > 0){
cout<<vect[0].first<<"\n";
}
else{
  cout<<"TLE\n";
}




  return 0;
}


