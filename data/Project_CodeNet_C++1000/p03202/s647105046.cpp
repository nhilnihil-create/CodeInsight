#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> P;

int N, a[200005];
vector<P> A; // firstの値がsecond個

void push(int x){ // a[i-1] < a[i]
  
  if( (int)A.size() != 0 && A[(int)A.size()-1].first == 1 ){
    A[(int)A.size()-1].second += x;
    return;
  }
  
  A.push_back( P( 1, x ) );
  
}

void pop(int x){ // a[i-1] > a[i]
  
  while(x){
    
    if( A[(int)A.size()-1].second <= x ){
      x -= A[(int)A.size()-1].second;
      A.pop_back();
    }
    else{
      A[(int)A.size()-1].second -= x;
      x = 0;
    }
    
  }
  
}

bool add(int x){ // a[i-1] = a[i]
  
  if( A.size() == 1 && A[0].first == x ) return false;  
  
  if( A[(int)A.size()-1].first == x ){
    
    int cnt = A[(int)A.size()-1].second;
    
    A.pop_back();
    
    int num = A[(int)A.size()-1].first;
    int cnt2 = A[(int)A.size()-1].second - 1;
    
    A.pop_back();
    
    if( cnt2 ) A.push_back( P( num, cnt2 ) );
    
    if( cnt2 == 0 && A.size() != 0 && A[(int)A.size()-1].first == num + 1 ){
      A[(int)A.size()-1].second++;
    }
    else A.push_back( P( num + 1, 1 ) );
    
    A.push_back( P( 1, cnt ) );
    
  }
  else{
    
    int num = A[(int)A.size()-1].first;
    int cnt = A[(int)A.size()-1].second - 1;
    
    A.pop_back();
    
    if( cnt ) A.push_back( P( num, cnt ) );
    
    if( cnt == 0 && (int)A.size() != 0 && A[(int)A.size()-1].first == num + 1 ){
      A[(int)A.size()-1].second++;
    }
    else A.push_back( P( num + 1, 1 ) );
    
  }
  
  return true;
}

bool check(int x){
  
  int pre = 0;
  
  for(int i=0;i<N;i++){
    
    if( pre < a[i] ) push( a[i] - pre );
    if( pre >= a[i] ){
      pop( pre - a[i] );
      if( add( x ) == false ) return false;
    }
    
    pre = a[i];
        
  }
  
  return true;
}

void solve(){
  
  if( check( 1 ) == true ){
    cout<<1<<endl;
    return;
  }
  
  int l = 1, r = 3e5;
  
  while( l + 1 < r ){
    
    int m = ( l + r ) / 2;
    
    A.clear();
    
    if( check( m ) == false ) l = m;
    else r = m;
    
  }
  
  cout<<r<<endl;
  
}

signed main(){
  
  cin>>N;
  
  for(int i=0;i<N;i++) cin>>a[i];
  
  solve();
  
  return 0;
}
