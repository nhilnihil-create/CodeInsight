#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string>S(N);
  for(int i=0;i<N;i++)
    cin >> S.at(i);
  map<char,int>namae;
  namae['M']=0,namae['R']=1,namae['A']=2,namae['C']=3,namae['H']=4;
  vector<int64_t>kazu(5,0);
  for(int i=0;i<N;i++){
    if(S.at(i).at(0)=='M'||S.at(i).at(0)=='R'||S.at(i).at(0)=='A'||S.at(i).at(0)=='C'||S.at(i).at(0)=='H'){
      kazu.at(namae[S.at(i).at(0)])++;
    }
  }
  int64_t ans=0;
  ans+=(kazu.at(0)*kazu.at(1)*kazu.at(2));
  ans+=(kazu.at(0)*kazu.at(1)*kazu.at(3));
  ans+=(kazu.at(0)*kazu.at(1)*kazu.at(4));
  ans+=(kazu.at(0)*kazu.at(2)*kazu.at(3));
  ans+=(kazu.at(0)*kazu.at(2)*kazu.at(4));
  ans+=(kazu.at(0)*kazu.at(3)*kazu.at(4));
  ans+=(kazu.at(1)*kazu.at(2)*kazu.at(3));
  ans+=(kazu.at(1)*kazu.at(2)*kazu.at(4));
  ans+=(kazu.at(1)*kazu.at(3)*kazu.at(4));
  ans+=(kazu.at(2)*kazu.at(3)*kazu.at(4));
  cout << ans << endl;
  return 0;
}