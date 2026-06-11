#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(void){
  int n,i,j,x,y;
  vector<P> r,b;
  
  cin >> n;
  for (i=0;i<n;i++){
    cin >> x >> y;
    r.push_back(P(y,x));
  }
  for (i=0;i<n;i++){
    cin >> x >> y;
    b.push_back(P(x,y));
  }
  
  sort(r.begin(),r.end(),greater<P>());
  sort(b.begin(),b.end());
  
  int ans=0,cx,cy;
  bool ru[105]={false};
  for (i=0;i<n;i++){
    cx=b[i].first;
    cy=b[i].second;
    j=0;
    while (j<n && (ru[j] || r[j].second>cx || r[j].first>cy)) j++;
    if (j<n){
      ans++;
      ru[j]=true;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}