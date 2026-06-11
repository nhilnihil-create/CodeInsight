#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int N_MAX = 50;
typedef pair<long long,long long> P;
int main()
{
  int n,k,i,j,l;
  long long x,y,res=LLONG_MAX;
  P p[N_MAX];
  vector<long long> q;
  cin >> n >> k;
  for(i=0;i<n;i++)
    cin >> p[i].first >> p[i].second;
  sort(p,p+n);
  for(i=0;i<n-k+1;i++){
    q.clear();
    x=p[i+k-1].first-p[i].first;
    for(j=i;j<i+k;j++)
      q.push_back(p[j].second);
    sort(q.begin(),q.end());
    y=q[k-1]-q[0];
    res=min(res,x*y);
    for(j=i+k;j<n;j++){
      q.push_back(p[j].second);
      sort(q.begin(),q.end());
      x=p[j].first-p[i].first;
      y=LLONG_MAX;
      for(l=0;l<=j-i-k+1;l++)
        y=min(y,q[l+k-1]-q[l]);
      res=min(res,x*y);
    }
  }
  cout << res << endl;
  return 0;
}