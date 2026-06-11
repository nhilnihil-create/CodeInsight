#include<bits/stdc++.h>  
using namespace std;
typedef long long ll;

int ask(int c){
  cout << c << endl; fflush(stdout);
  string d; cin >> d;
  if( d[0] == 'V'){ exit(0);}
  
  return d[0] == 'M';
} //男が帰ってきたら１を、女が帰ってきたら0を返す
 
  
int main(){ 
  int N; cin >> N;
  int lb = 0; int lbt = ask(0);
  int ub = N-1; int ubt = ask(N-1);
  
  while(true){
    int mid = (lb+ub)/2;
    int midt = ask(mid);
    
    if( abs(mid-lb)%2 != abs(lbt-midt)%2){
      ub = mid;
      ubt = midt;
    }
    else{
      lb = mid;
      lbt = midt;
    }
  }
  
}