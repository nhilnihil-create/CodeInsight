#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N;
  cin>>N;
  vector<int> b(N);
  for(int i=0;i<N;i++){
    cin>>b.at(i);
  }
  vector<int> a(N);
  bool flag=true;
  for(int i=0;i<N;i++){
    bool sub=true;
    for(int j=N-i-1;j>=0;j--){
      if(b.at(j)==j+1){
        a.push_back(b.at(j));
        b.erase(b.begin()+j);
        sub=false;
        break;
      }
    }
    if(sub){
      flag=false;
      break;
    }
  }
  if(!flag){
    cout<<-1<<endl;
  }else{
    reverse(a.begin(),a.end());
    for(int i=0;i<N;i++){
      cout<<a.at(i)<<endl;
    }

  }

}
