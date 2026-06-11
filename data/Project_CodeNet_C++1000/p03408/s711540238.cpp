#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector <string> t(n);/*該当する文字列*/
  vector <int> num(n,0);/*上記に対応するもらえるかねの配列*/
  for(int i=0;i<n;i++){
    string t_n;
    cin >> t_n;
    for(int j=0;j<n;j++){
      if(t.at(j)==t_n){
        num.at(j)++;
        break;
      }else if(t.at(j)==""){
        num.at(j)=1;
        t.at(j)=t_n;
        break;
      }
    }
  }
  
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    string t_n;
    cin >> t_n;
    for(int j=0;j<n;j++){
      if(t.at(j)==t_n){
        num.at(j)--;
        break;
      }else if(t.at(j)==""){
        break;
      }
    }
  }
  
  int max=0;
  for(int i=0;i<n;i++){
    if(num.at(i)>max){
      max=num.at(i);
    }
  }
  cout << max << endl;
  return 0;
}