#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 100
vector<int> p;
vector<bool> p_table(MAX+1,true);
void prime(){
  p_table.at(0)=false,p_table.at(1)=false;
  for(int i=2;i<=MAX;i++){
    if(p_table.at(i)){
      p.push_back(i);
      for(int j=2;i*j<=MAX;j++){
        p_table.at(i*j)=false;
      }
    }
  }
}

int main(){
  int N;
  cin>>N;
  prime();
  int n=p.size();
  vector<int> p_count(n,0);
  for(int i=2;i<=N;i++){
    int k=0;
    int j=i;
    while(j>1){
      if(j%p.at(k)==0){
        p_count.at(k)++;
        j/=p.at(k);
      }else{
        k++;
      }
    }
  }
  sort(p_count.begin(),p_count.end());
  int k74=lower_bound(p_count.begin(),p_count.end(),74)-p_count.begin();
  int k24=lower_bound(p_count.begin(),p_count.end(),24)-p_count.begin();
  int k2=lower_bound(p_count.begin(),p_count.end(),2)-p_count.begin();
  int k14=lower_bound(p_count.begin(),p_count.end(),14)-p_count.begin();
  int k4=lower_bound(p_count.begin(),p_count.end(),4)-p_count.begin();

  int ans=0;
  ans+=n-k74;
  ans+=(n-k24)*(n-k2-1);
  ans+=(n-k14)*(n-k4-1);
  ans+=(n-k4)*(n-k4-1)/2*(n-k2-2);
  cout<<ans<<endl;
}
