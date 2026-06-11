#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, x[1005], y[1005];
int odd, even, bit;
vector<int> v;

void calc(int U, int V){
  
  int flagU = 0, flagV = 0;
  
  if( U < 0 ){
    flagU = 1;
    U = abs(U);
  }
  
  if( V < 0 ){
    flagV = 1;
    V = abs(V);
  }
  
  int A = (1LL<<bit) - 1;
  
  if( even ) A = (1LL<<(bit-1)) - 1 + 1;
  
  vector<int> a;
  
  for(int i=(int)v.size()-1;i>=0;i--){
    
    if( A - 2 * v[i] >= U ){
      A -= 2 * v[i];
      a.push_back(-1);
    }else{
      a.push_back(1);
    }
    
  }
  
  reverse( a.begin(), a.end() );
    
  int B = (1LL<<bit) - 1;
  
  if( even ) B = (1LL<<(bit-1)) - 1 + 1;
  
  vector<int> b;
  
  for(int i=(int)v.size()-1;i>=0;i--){
    
    if( B - 2 * v[i] >= V ){
      B -= 2 * v[i];
      b.push_back(-1);
    }else{
      b.push_back(1);
    }
    
  }
  
  reverse( b.begin(), b.end() );
  
  if( flagU ){
    
    for(int i=0;i<(int)a.size();i++) a[i] *= -1;
    
  }
  
  if( flagV ){
    
    for(int i=0;i<(int)b.size();i++) b[i] *= -1;
    
  }
  
  vector<char> ans;
  
  for(int i=0;i<(int)a.size();i++){
    
    if( a[i] == -1 && b[i] == -1 ) ans.push_back('L');
    if( a[i] == 1 && b[i] == 1 ) ans.push_back('R');
    if( a[i] == 1 && b[i] == -1 ) ans.push_back('U');
    if( a[i] == -1 && b[i] == 1 ) ans.push_back('D');
    
  }

  for(int i=0;i<(int)v.size();i++){
    cout<<ans[i];
  }

  cout<<endl;
  
}

signed main(){
  
  cin>>N;
  
  for(int i=0;i<N;i++){
    cin>>x[i]>>y[i];
    if( abs( x[i] + y[i] ) % 2 == 1 ) odd = 1;
    else even = 1;
  }
  
  if( odd == 1 && even == 1 ){
    cout<<-1<<endl;
    return 0;
  }
  
  if( even ){
    cout<<33<<endl;
    bit = 33;
  }
  else{
    cout<<32<<endl;
    bit = 32;
  }
  
  if( even ){
    v.push_back(1);
    cout<<1<<' ';
  }
  
  for(int i=0;i<=31;i++){
    v.push_back(1LL<<i);
    cout<<(1LL<<i);
    if( i != 31 ) cout<<' ';
  }
  
  cout<<endl;
  
  for(int i=0;i<N;i++){
    calc( x[i] + y[i], x[i] - y[i] );
  }
  
  return 0;
}
