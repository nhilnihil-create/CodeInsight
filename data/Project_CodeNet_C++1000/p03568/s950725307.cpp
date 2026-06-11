#include <bits/stdc++.h>
using namespace std;

int N;
int ans=0;
void dfs(vector<int> &A,vector<int> &B,int now){
  if(now==N){
    for(int i=0;i<N;i++){
      if(B.at(i)%2==0){
        ans++;
        return;
      }
    }
    return;
  }

  for(int i=-1;i<=1;i++){
    B.at(now)=A.at(now)+i;
    dfs(A,B,now+1);
  }
}

int main(){
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++)  cin >> A.at(i);

  vector<int> B(N);
  dfs(A,B,0);
  cout << ans << endl;

  return 0;
}