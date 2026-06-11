#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s[N];
  for(int i=0;i<N;i++){
    cin >> s[i];
  }
  int M;
  cin >> M;
  string t[M];
  for(int i=0;i<M;i++){
    cin >> t[i];
  }
  vector<int> score(N+M,0);
  string str[N+M];
  int k=0;
  bool flag=false;
  for(int i=0;i<N;i++){
    str[k]=s[i];
    flag=false;
    for(int j=0;j<k;j++){
      if(str[j]==str[k]){
        score.at(j)++;
        break;
      }
      if(j+1==k){
        flag=true;
      }
    }
    if(k==0||flag==true){
      score.at(k)++;
      k++;
      continue;
    }
  }
  for(int i=0;i<M;i++){
    str[k]=t[i];
    flag=false;
    for(int j=0;j<k;j++){
      if(str[j]==str[k]){
        score.at(j)--;
        break;
      }
      if(j+1==k){
        flag=true;
      }
    }
    if(k==0||flag==true){
      score.at(k)--;
      k++;
      continue;
    }
  }
  int tmp=0;
  for(int i=0;i<k;i++){
    if(tmp<score.at(i)){
      tmp=score.at(i);
    }
  }
  cout << tmp << endl;
}
