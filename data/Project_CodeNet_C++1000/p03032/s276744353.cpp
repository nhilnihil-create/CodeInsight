#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()

int main(){
  int N,K;cin>>N>>K;
  vector<int> D(N);
  for(int i=0; i<N; i++)cin>>D[i];
  int A,B,R=min(N,K);
  vector<int> GET;
  ll MAX = 0;
  for(A=0; A<=R; A++){
    for(B=0; A+B<=R; B++){
      ll sum = 0;
      GET.clear();
      int i=0;
      for(auto itr=D.begin(); i<A; i++,itr++){
        GET.push_back(*itr);
        sum += *itr;
      }
      int j=0;
      for(auto itr=D.end()-1; j<B; j++,itr--){
        sum += *itr;
        GET.push_back(*itr);
      }
      
      sort(all(GET),greater<int>());
      //DEBUG(GET);

      for(int i=0; i<K-A-B; i++){
        if(GET.empty())break;
        int x = GET.back();
        if(x>0)break;
        GET.pop_back();
        sum -= x;
      }
      //DEBUG(A,B,sum);
      MAX = max(MAX, sum);
    }
  }
  cout<<MAX<<endl;
}