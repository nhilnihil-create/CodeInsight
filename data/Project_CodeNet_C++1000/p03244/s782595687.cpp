#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<int> odd(1e5+1,0),even(1e5+1,0);
  for(int i=0;i<n;i+=2) odd[v[i]]++;
  for(int i=1;i<n;i+=2) even[v[i]]++;
  int ido=(int)(max_element(odd.begin(),odd.end())-odd.begin());
  int ide=(int)(max_element(even.begin(),even.end())-even.begin());
  sort(odd.begin(),odd.end());
  sort(even.begin(),even.end());
  int ans;
  if(ido==ide){
    ans=max(odd.back()+*(even.end()-2),even.back()+*(odd.end()-2));
  }
  else{
    ans=odd.back()+even.back();
  }
  cout<<n-ans<<endl;
  return 0;
}
    
