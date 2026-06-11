#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,j,l,n,k,m;
  vector<int> a,b;
  cin >> n >> k;
  for(i=0;i<n;i++){
    int v;
    cin >> v;
    a.push_back(v);
  }
  int ans=0;
  for(i=n-1;i>=0;i--){
    b.push_back(a[i]);
  }
  for(i=0;i<=k;i++){
    for(j=0;j<=i/2;j++){
      int x=i-j;
      if(j>n || x>n || x<j){
        continue;
      }
      for(l=0;l<=x;l++){
        vector<int> y;
        for(m=0;m<l;m++){
          y.push_back(a[m]);
        }
        for(m=0;m<x-l;m++){
          y.push_back(b[m]);
        }
        sort(y.begin(),y.end(),greater<int>());
        for(m=0;m<j;m++){
          y.pop_back();
        }
        int sum=0;
        for(m=0;m<y.size();m++){
          sum+=y[m];
        }
        ans=max(ans,sum);
      }
    }
  }
  cout << ans << endl;
  return 0;
}