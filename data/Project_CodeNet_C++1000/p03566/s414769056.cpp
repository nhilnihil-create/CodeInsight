#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  vector<double> v(n);
  int sumt=0;
  for (int i = 0; i < n; i++){
    cin >> t[i];
    sumt+=t[i];
  } 
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<double> maxv(sumt*2+1,101);

  int left=0;
  int right=0;
  for (int i = 0; i < n; i++)
  {
    left=right;
    right += t[i]*2;
    for (int j = left; j <= right; j++)
    {
      maxv[j]=min(maxv[j],v[i]);
    }
  }
  maxv[0] = 0;
  maxv[right] = 0;

  for (int i = 1; i < sumt*2+1; i++)
  {
    maxv[i] = min(maxv[i],maxv[i-1]+0.5);
  }

  for (int i = sumt*2-1; i > 0; i--)
  {
    maxv[i] = min(maxv[i],maxv[i+1]+0.5);
  }

  double x = 0.0;
  for (int i = 0; i < sumt*2; i++)
  {
    x += 0.25*(maxv[i]+maxv[i+1]);
  }

  printf("%.9lf\n",x);
}