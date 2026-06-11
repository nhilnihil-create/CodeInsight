#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

#define N 2005

int in[N];
pair<int,int> pp[N];
bool isErased[N];

int isPossible(int n,int k,int q) {
  isErased[n+1] = true;
  int last = 1,ret = 0;
  vector<int> cand,tmp;
  for(int i=1;i<=n+1;++i) {
    if(isErased[i]) {
      if(tmp.size()>=k) {
        sort(tmp.begin(),tmp.end());
        for(int j=0;j+k-1<tmp.size();++j) {
          cand.push_back(tmp[j]);
        }
      }
      tmp.clear();
    } else {
      tmp.push_back(in[i]);
    }
  }
  if(cand.size()>=q) {
    sort(cand.begin(),cand.end());
    return cand[q-1] - cand[0];
  } else {
    return 1e9;
  }
}
void solve() {
  int n,k,q;scanf("%d %d %d",&n,&k,&q);
  if(q==1) {
    printf("0\n");
    return;
  }
  for(int i=1;i<=n;++i) {
    scanf("%d",&in[i]);
    pp[i] = make_pair(in[i],i);
  }
  sort(pp+1,pp+n+1);
  int ret = 1e9;
  for(int i=1;i<=n;) {
    int j;
    vector<int> v;
    for(j= i;j<=n;++j) {
      if(pp[j].first != pp[i].first) {
        break;
      }
      v.push_back(pp[j].second);
    }
    ret = min(ret, isPossible(n,k,q));
    i = j;
    for(j=0;j<v.size();++j) {
      isErased[v[j]] = true;
    }
  }
  printf("%d\n",ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
