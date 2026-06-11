#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<vector<double>>vec(a,vector<double>(2));
  ll b;
  cin>>b;
  ll e;
  cin>>e;
  for(ll i=0;i<a;i++){
    double c;
    cin>>c;
    vec.at(i).at(0)=b-c*0.006;
    vec.at(i).at(1)=i;
  }
  sort(vec.begin(),vec.end());
  ll f=a-1;
  for(ll i=0;i<a;i++){
    if(e<=vec.at(i).at(0)){
      f=i;
      break;
    }
  }
  if(f==0){
    cout<<vec.at(f).at(1)<<endl;
    return 0;
  }
  if(abs(vec.at(f).at(0)-e)>abs(vec.at(f-1).at(0)-e)){
    cout<<vec.at(f-1).at(1)+1<<endl;
  }
  else{
    cout<<vec.at(f).at(1)+1<<endl;
  }
  
    
  return 0;
}
    
    
  
