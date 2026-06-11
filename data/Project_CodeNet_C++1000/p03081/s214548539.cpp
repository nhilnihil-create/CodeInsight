#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
  
  int N,Q; cin >> N >> Q;
  
  string s; cin >> s;
  
  vector<char> t(Q),d(Q);
  
  for(int i = 0; i < Q; i++){ cin >> t[i] >> d[i];}
  
  int Lmost,Rmost;
  // 落ちる区間の最左端と最右端を求める
  
  int left = -1; int right = N; //まずはLmostから求める
  
  while( right-left > 1){
    
    int mid = (left+right)/2; //この位置のゴーレムがQ回の操作で左端まで到達するかを判定
    
    int pos = mid; //現在地
    
    for(int i = 0; i < Q; i++){ 
      if( t[i] != s[pos]){ continue;}
      
      if( d[i] == 'L'){ pos--;}
      else{ pos++;}
      
      if( pos < 0 || pos >= N){ break;}
    }
    
    if(pos < 0){ //もうちょいleftを大きくできる
      left = mid;}
    
    else{
      right = mid;}
  }
  
  Lmost = left;
  
  left = -1; right = N;
  
  while( right-left > 1){
    
    int mid = (left+right)/2;
    
    int pos = mid;
    
    for(int i = 0; i < Q; i++){
      
      if( t[i] != s[pos]){ continue;}
      
      if( d[i] == 'L'){ pos--;}
      else{ pos++;}
      
      if(pos < 0 || pos >= N){ break;}
    }
    
    
    if( pos >= N ){ right = mid;} //もうちょいrightを小さくしたい
    else{ left = mid;}
  }
  
  Rmost = right;
  
  // Lmost,Rmostがそれぞれ条件を満たすか判定
  
  int ans = N;
  
  int pos = Lmost;
  
  for(int i = 0; i < Q; i++){
    
    if(t[i] != s[pos]){ continue;}
    
    if( d[i] == 'L'){ pos--;}
    else{ pos++;}
 
    if( pos < 0 || pos >= N){ break;}
  }
  
  if( !(pos < 0)){ //ここを含まない
    Lmost--;
  }
    
  pos = Rmost;
  
  for(int i = 0; i < Q; i++){
    
    if(t[i] != s[pos]){ continue;}
    
    if( d[i] == 'L'){ pos--;}
    else{ pos++;}
    
    if( pos < 0 || pos >= N){ break;}
    
  }
  
  if( !(pos >= N)){ //ここを含まない
    Rmost++;
  }
  
  ans -= (Lmost-Rmost+N+1);
  
  cout << ans << endl;
  
  return 0;
} 