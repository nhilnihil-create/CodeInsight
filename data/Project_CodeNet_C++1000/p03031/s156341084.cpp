#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int> > S(M);
  int P[M];
  for(int i=0;i<M;i++){
    int k=0;
    cin >> k;
    S[i].resize(k);
    for(int j=0;j<k;j++){
      int s;
      cin >> s;
      S[i][j]=s-1;
    }
  }
  for(int p=0;p<M;p++){
    cin>>P[p];
  }
  int goal = 0;
  for (int bit = 0; bit < (1<<N); ++bit){
    bool sw = true;
    for (int j=0;j<M;j++){
      int ans =0;
      for (int i = 0; i < (int)S[j].size(); ++i) {
	if (bit & (1<<S[j][i])) {
	  ans += 1;
	}
      }
      if (ans%2 != P[j]){
	sw = false;
	break;
      }
    }
    if(sw) goal++;
  }
  cout << goal <<endl;
  
}
