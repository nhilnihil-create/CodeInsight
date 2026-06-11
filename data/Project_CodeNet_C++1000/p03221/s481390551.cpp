#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
using ll = long long int;
using pii = pair<int, int>;

int main() {
  int n,m; cin>>n >>m;
  vector<pair<pii, int> > v(m);
  rep(i,m){
    cin>>v[i].first.first >>v[i].first.second; 
    v[i].second =i;
  }
  sort(v.begin(), v.end());
  vector<pii>  vec(m);
  rep(i,m){
    int j= v[i].second;
    vec[j].first= v[i].first.first;
    if(i==0 ){vec[j].second= 1;}
    else if(v[i].first.first!= v[i-1].first.first ){
      vec[j].second=1;
    }
    else{vec[j].second= vec[v[i-1].second ].second+1;}
  }

  rep(i,m){
    int n1=vec[i].first;
    int n2= vec[i].second;
    printf("%06d",n1);   
    printf("%06d",n2);
    cout<<endl;
  }
}

