#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(int v){ //席vについて尋ねる
  
  cout << v << endl;
  fflush(stdout);
  string s; cin >> s;
  if( s == "Vacant"){ exit(0);}
  if( s == "Male"){ return 1;}
  else{ return 2;}
  
}

int main(){
  int N; cin >> N;
  int left = 0; int right = N-1; 
  
  vector<int> gender(N,0); //0は未定
  
  gender[0] = ask(0);
  gender[N-1] = ask(N-1);
  
  while(right-left > 1){
    
    int mid = (right+left)/2;
    
    gender[mid] = ask(mid);
    
    if( abs(gender[mid]-gender[left])!= abs(left-mid)%2){ right = mid;}
    //両端が同性でかつ間の長さが奇数長のときに、反対側に進む
    else{ left = mid;}
      
    
    
  }

  
  return 0;
}