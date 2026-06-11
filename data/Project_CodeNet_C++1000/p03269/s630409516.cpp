#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)



int main(){
  int l;
  cin >> l;
  int k=0;
  while(l/((int) pow(2,k))!=0){
    k++;
  }
  vector<tuple<int, int, int> > g;
 // cout << k << endl;
  rep(i,k-1){
    g.pb(make_tuple(i+1,i+2,pow(2,k-2-i)));
    g.pb(make_tuple(i+1,i+2,0));
  }
  
  int kt=k;
  int lt=l;
  while(lt-pow(2,kt-1)>0){
    lt-=pow(2,kt-1);
    kt=0;
    while(lt/((int) pow(2,kt))!=0){
      kt++;
    }
    g.pb(make_tuple(1,k-kt+1,l-lt));
  }
  cout << k << " " << g.size() << endl;
  rep(i,g.size()){
    int& u=get<0>(g[i]);
    int& v=get<1>(g[i]);
    int& w=get<2>(g[i]);
    cout << u << " " << v << " " <<  w <<endl;
  }
  
  return 0;

}
