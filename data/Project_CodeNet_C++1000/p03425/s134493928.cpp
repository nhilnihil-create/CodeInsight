#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ;
  cin >> N ; 
  vector<string> S(N) ; 
  int cnt = 0 ; 
  int cnt_M = 0 , cnt_A = 0 , cnt_C = 0 , cnt_R = 0 , cnt_H = 0 ;
  for(int i = 0 ; i < N ; i++){
    cin >> S.at(i) ; 
    if(S.at(i).at(0) == 'M'){
      cnt_M++ ; 
    }
    else if(S.at(i).at(0) == 'A'){
      cnt_A++ ; 
    }
    else if(S.at(i).at(0) == 'R'){
      cnt_R++ ; 
    }
    else if(S.at(i).at(0) == 'C'){
      cnt_C++ ; 
    }
    else if(S.at(i).at(0) == 'H'){
      cnt_H++ ;  
    }
  }
  int P[10]={0,0,0,0,0,0,1,1,1,2};
  int Q[10]={1,1,1,2,2,3,2,2,3,3};
  int R[10]={2,3,4,3,4,4,3,4,4,4};  
  
  vector<long long> T(5) ;
  T.at(0) = cnt_M ; 
  T.at(1) = cnt_A ; 
  T.at(2) = cnt_R ; 
  T.at(3) = cnt_C ; 
  T.at(4) = cnt_H ;  
  
  long long ans = 0 ; 
  for(int i = 0 ; i < 10 ; i++){
    ans += T.at(P[i])*T.at(Q[i])*T.at(R[i]) ;
  }
  cout << ans << endl;
}