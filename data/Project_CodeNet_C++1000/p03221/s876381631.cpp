#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;


int keta(int64_t x){
  int64_t count=1;
  while(x/10!=0){
    x/=10;
    count++;
  }
  return count;
}


int main() {
  int N,M;
  cin>>N>>M;
  vector<vector<pair<int64_t,int64_t>>> SS(N);
  vector<pair<int64_t,int64_t>> ans;
  //県ごとに年と市の番号のpairを作る
  for(int i=0;i<M;i++){
    int64_t a,b;
    cin>>a>>b;
    SS.at(a-1).push_back(make_pair(b,i));
  }
  //県ごとに並び替え
  for(int64_t i=0;i<N;i++){
    if(SS.at(i).size()==0)continue;
  sort(SS.at(i).begin(),SS.at(i).end());
  }
  //認識番号と市の番号のpairを作る
  for(int64_t i=0;i<N;i++){
    for(int64_t j=0;j<SS.at(i).size();j++){
      int64_t c=SS.at(i).at(j).second;
      ans.push_back(make_pair(c,(i+1)*1000000+(j+1)));
    }
  }
  //市の番号順に並び替え
  sort(ans.begin(),ans.end());
  
  for(int64_t i=0;i<(int64_t)ans.size();i++){
    int64_t d=keta(ans.at(i).second);
    for(int64_t j=0;j<12-d;j++) cout<<0; //0を埋める
    cout<<ans.at(i).second<<endl;
  }
  
}
