#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> p(M),y(M);
  
  for(int i=0;i<M;i++){
    cin>>p[i]>>y[i];
    p[i]--;
  }

  vector<vector<int>> task(N);//県の数だけ配列を準備
  for(int i=0;i<M;i++){
    task[p[i]].push_back(y[i]);//各県の配列に市を挿入
  }
  for(int i=0;i<N;i++){
    sort(task[i].begin(),task[i].end());
  }
  for(int i=0;i<M;i++){
    cout<<setfill('0')<<right<<setw(6)<<p[i]+1;
    //該当市の含まれる県の配列中の該当市の位置は先頭から何番目か　0オリジンなので出力時に1を足す
    int id=lower_bound(task[p[i]].begin(),task[p[i]].end(),y[i])-task[p[i]].begin();
    cout<<setfill('0')<<right<<setw(6)<<id+1;
    cout<<endl;
  }
   
  return 0;
}
