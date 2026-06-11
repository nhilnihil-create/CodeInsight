#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  int N,M;
  cin >> N;
  vector <int> D(N);
  rep(i,N)
    cin >> D.at(i);
  
  cin >> M;
  vector <int> T(M);
  rep(i,M)
    cin >> T.at(i);
  
  if(M>N){
    cout << "NO" << endl;
    return 0;
  }
  
  int tmp=0;
  sort(D.begin(),D.end());
  sort(T.begin(),T.end());
  
  rep(i,M){
    for(int j=tmp;j<N;j++){
      if(T.at(i)==D.at(j)){
        tmp=j+1;
        D.at(j)=0;
          break;
      }
      else if(T.at(i)<D.at(j)){
        //cout << i << j << endl;
        cout << "NO" << endl;
        return 0;
      }
 	 }	
  	}
  cout << "YES" << endl;
}