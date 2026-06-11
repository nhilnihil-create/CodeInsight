#include<iostream>

using namespace std;
char table[310][310];
char tableT[310][310];

int main(void){
  int N;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> table[i];
    for(int j=0;j<N;j++){
      tableT[j][i]=table[i][j];
    }
  }
  int ans=0;
  for(int k=0;k<N;k++){
    bool symflag=true;
    for(int i=0;i<N;i++){
      int ikp=i+k;
      ikp = ikp>=N ? ikp-N : ikp;
      for(int j=0;j<N;j++){
        int jkn= j>=k ? j-k : j-k+N;
        symflag &= (table[i][j]==tableT[ikp][jkn]);
      }
    }
    if(symflag){
      ans+=N;
      //cout << k << endl;
    }
  }
  cout << ans << endl;
  return 0;
}