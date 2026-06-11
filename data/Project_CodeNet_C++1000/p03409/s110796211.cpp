#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N_MAX = 100;
typedef pair<int,int> P;
int main()
{
  int n,i,j=0,res=0;
  P r[N_MAX],b[N_MAX];
  vector<int> v={};
  vector<int>::iterator it;
  cin >> n;
  for(i=0;i<n;i++)
    cin >> r[i].first >> r[i].second;
  for(i=0;i<n;i++)
    cin >> b[i].first >> b[i].second;
  sort(r,r+n,greater<P>());
  sort(b,b+n,greater<P>());
  for(i=0;i<n;i++){
    for(;j<n&&b[j]>r[i];j++)
      v.push_back(b[j].second);
    if(v.empty()) continue;
    sort(v.begin(),v.end());
    it=upper_bound(v.begin(),v.end(),r[i].second);
    if(it!=v.end()){
      res++;
      v.erase(it);
    }
  }
  cout << res << endl;
  return 0;
}
