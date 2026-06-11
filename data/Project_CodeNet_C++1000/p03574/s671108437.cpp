#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,M;
      cin >> N >> M;
  vector<vector<char>> sheet(N,vector<char>(M));
  froop1(0,N){
	for(int j = 0;j < M;j++){
      cin >> sheet.at(i).at(j);
    }
  }
  vector<vector<int>> output(N,vector<int>(M,0));
  froop1(0,N){
    for(int j = 0;j < M;j++){
      if(sheet.at(i).at(j) == '.'){
        
        for(int k = i - 1;k <= i + 1;k++){
          for(int l = j - 1;l <= j + 1;l++){
           if(k >= 0 && l >= 0 && k < N && l < M && !(k == i && l == j)){
             if(sheet.at(k).at(l) == '#') output.at(i).at(j)++;
           }
          }
        }
      }
    }
  }
      froop1(0,N){
        for(int j = 0;j < M;j++){
          if(sheet.at(i).at(j) == '#'){
            cout << '#';
          }else{
			cout << output.at(i).at(j);
          }
        }
        cout << endl;
      }
}
