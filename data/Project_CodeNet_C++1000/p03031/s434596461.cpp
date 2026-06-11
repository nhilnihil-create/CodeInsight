#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main() {
 int N,M;
 cin>>N>>M;
  int ans=0;
  vector<int>a(N);
  for(int i=0;i<M;i++){
  int K;
    cin>>K;
   for(int j=0;j<K;j++){
   		int s;
        cin>>s;
      	s--;
      a.at(s) |= 1<<i;
	  }
  }
  int P=0;
  for(int i=0;i<M;i++){
    int x;
    cin>>x;
    P |=x<<i;
  }
  for(int s=0;s< (1<<N);s++){
  int t=0;
    for(int i=0;i<N;i++){
    if(s>>i &  1){
    	t ^=a.at(i);
      }
    }
    if(t==P){
    ans++;
    }
  }
  cout<<ans<<endl;
}
