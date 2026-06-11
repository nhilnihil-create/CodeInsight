#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int x[100000];
  for(int i=0;i<m;i++){
    cin>>x[i];
  }
  sort(x,x+m);
  vector<int> d;
  for(int i=1;i<m;i++){
    d.push_back(x[i]-x[i-1]);
  }
  sort(begin(d),end(d));
  int ans=x[m-1]-x[0];
  for(int i=0;i<min<int>(n-1,d.size());i++){
    ans-=d[d.size()-1-i];
  }
  cout<<ans<<endl;
}

  
