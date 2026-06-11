#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int N,C;
  cin>>N>>C;
  vector<int> s(N),t(N),c(N);
  for(int i=0;i<N;i++){
    cin>>s.at(i)>>t.at(i)>>c.at(i);
    c.at(i)--;
  }

  vector<vector<int>> record(C,vector<int>(100005,0));
  for(int i=0;i<N;i++){
    record.at(c.at(i)).at(s.at(i))++;
    record.at(c.at(i)).at(t.at(i)+1)--;
  }
  int ans=0;
  for(int i=1;i<100005;i++){
    int count=0;
    for(int j=0;j<C;j++){
      record.at(j).at(i)+=record.at(j).at(i-1);
      if(record.at(j).at(i)>0){
        count++;
      }
    }
    ans=max(ans,count);
  }
  cout<<ans<<endl;
}
