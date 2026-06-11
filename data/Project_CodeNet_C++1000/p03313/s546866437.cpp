#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;

int main(){
  int N;cin>>N;
  int M=(int)pow(2, N);
  vll A;
  for (int i=0;i<M;++i){ll a;cin>>a;A.push_back(a);}
  vi vertices[M];
  vi layers[N+1];
  for (int i=0;i<M;++i){
    int count=0;
    for (int j=0;j<N+1;++j){
      int d=(i>>j)&1;
      if (d==1){
        vertices[i].push_back(i-(int)pow(2, j));
        count++;
      }
    }
    layers[count].push_back(i);
  }


  vllll first(M);
  for (int i=0;i<M;++i){
    first[i]=make_pair(A[i],i);
  }
  
  vllll second(M);
  second[0]=make_pair(0,0);
  vllll candidates[M];

  for (int layer=1;layer<N+1;++layer){
    int L=layers[layer].size();
    for (int l=0;l<L;++l){
      int i=layers[layer][l];
      int S=vertices[i].size();
      llll p=make_pair(A[i], i);
      candidates[i].push_back(p);
      for (int j=0;j<S;++j){
        llll q=first[vertices[i][j]];
        candidates[i].push_back(q);
      }
      sort(candidates[i].begin(), candidates[i].end(), greater<llll>());
      
      first[i]=candidates[i][0];
      int T=candidates[i].size();
      for (int t=0;t<T;++t){
        if (candidates[i][t]==candidates[i][0]){continue;}
        second[i]=candidates[i][t];
        break;
      }  
    }
  }

  
  vll ans;
  ans.push_back(first[1].first+second[1].first);
  if(M!=2){
    for (int k=2;k<M;++k){
      ll a=max(first[k].first+second[k].first,ans[k-2]);
      ans.push_back(a);
    }
  }

  for (int k=0;k<M-1;++k){
    cout << ans[k] << endl;
  }
  return 0;
}

