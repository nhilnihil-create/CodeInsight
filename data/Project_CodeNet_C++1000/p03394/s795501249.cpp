#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int range = 3e5+10;
bool used[range];
bool chosen[range];

int main(){
 int N; cin >> N;
  
  if( N < 6){
    
    if(N == 3){ cout << 2 << " " << 5 << " " << 63 << endl;}
    else if( N == 4){ cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;}
    else{ cout << 2 << " " << 5 << " " << 20 << " "<< 30 << " " << 63 << endl;}
    
    return 0;
    
  }
  else{
 
  
  priority_queue<int,vector<int>,greater<int>> Q;
  

  for(int i = 1; i <= range; i++){ 
    if(i%2 == 0){ Q.push(i); used[i] = true; }
    if(i%3 == 0 && !used[i]){ Q.push(i); used[i] = true;} 
  }
  
  ll test = 0;
    
    vector<bool> chosen(range,false);
    
    int last = 0;
    
    while(N--){
    ll p = Q.top(); Q.pop();
    test += p; chosen[p] = true; last = p;
    
    
  }
  
    
   
  if( test%6 == 2){
    
    chosen[8] = false; 
    
    for(int i = last+1; i <= range; i++){ 
      if(i%6 == 0){ chosen[i] = true; break;}
      
    }
  }
  else if( test%6 == 3){
    chosen[9] = false; 
    
    for(int i = last+1; i <= range; i++){ 
      if(i%6 == 0){ chosen[i] = true; break;}
      
    }
    
  }
  
  else if(test%6 == 5){ //test%6 == 5
    chosen[9] = false; 
    
    for(int i = last+1; i <= range; i++){ 
      if(i%6 == 4){ chosen[i] = true; break;}
      
    }
  }
  
  //出力
    
  for(int i = 0; i <= range; i++){ 
    if(chosen[i]){ cout << i << " ";}
  }
  
  cout << endl;
  
  }
  return 0;
}
  