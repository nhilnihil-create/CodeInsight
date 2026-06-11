#include<bits/stdc++.h>

using namespace std;

int main(){ 
  int time[30]; bool table[30];
  int N; cin>> N;
  for(int i = 0; i < 30; i++){ time[i] = 0; table[i] = false;}
  time[0] = 1;//高橋くん自身
   
 for(int i = 0; i < N; i++){ int d; cin >> d; time[d]++;}
  
  int ans = 0; vector<int> vec;
  
  if( time[0] >= 2 || time[12] >= 2){ //時刻０か１２に2人以上いる場合は０;
    cout << 0 << endl; return 0;}
    
  if( time[0] == 1){ table[0] = true;} if( time[12] == 1){ table[12] = true;}
  
  for(int j = 1; j < 12; j++){ // 1 ~ 11 への場合分けは解説PDF準拠
    if( time[j] >= 3){ cout << 0 << endl; return 0;} 
    if( time[j] == 1){ vec.push_back(j); } //可変成分(1人しかいない）をvecに格納
    if( time[j] == 2){ table[j] = true; table[24-j] = true;}
    //ちょうど２人いる場合は左右で固定（tableに記録）
   
  }
  
  //以下は時刻０、１２に1人以下しかおらず、かつ全ての時刻について３人以上いることはない。
  
  int n = (int) vec.size();
  
  for(int i = 0; i < ( 1 << n); i++){
    //高々2^11通りをbit演算
    for(int j = 0; j < n; j++){
      if( i & ( 1 << j)){ vec[j] = 24 - vec[j];}}
    
    vector<int> clock;
    for(int k = 0; k < 30; k++){ 
      if( table[k]){ clock.push_back(k);}}
    
    for(int k = 0; k < n; k++){
      clock.push_back(vec[k]);} 
    
    sort(clock.begin(),clock.end());
    
    int diff0 = abs(clock.front() - clock.back());
   
    int res = min( diff0, 24 - diff0);
    for(int k = 1; k < (int) clock.size() ; k++){
      int diff = abs(clock[k] - clock[k-1]);
     
      res = min( res, min( diff, 24 - diff));}
    
    ans = max( res, ans); 
    
     for(int j = 0; j < n; j++){
      if( i & ( 1 << j)){ vec[j] = 24 - vec[j];}}//復元
  }
  
  cout << ans << endl; return 0;}
    
      
      
      
    
  
  
  

  
  