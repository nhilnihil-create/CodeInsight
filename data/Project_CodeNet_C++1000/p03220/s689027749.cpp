#include <bits/stdc++.h>
using namespace std;



int main() {
	int N;
  	double T,A;
  	cin >> N >> T >> A;
  
  //平均気温
  double t[N];
  for (int i = 0;i<N;i++){
  double H;
  cin >> H;
    t[i] =T-H*0.006;
  }
    
    int ans = 0;
  
  for (int i=1;i<N;i++){
  //絶対値求めてiからのほうが近ければ更新
   if(abs(A -t[i])<abs(A-t[ans]))
     ans=i;
     }
  cout <<ans+1<<endl;
    }
 