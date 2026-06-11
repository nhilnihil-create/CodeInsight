#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const long long INF = 1LL << 60;
bool mem[100010];
int memo[100010];
int N;
int h[100010];
int DFS(int i) {
  ll ans;
    if(mem[i]==true){
        ans= memo[i];
    }
    else if(i==0){
      	ans=0;
      	mem[0]=true;
    }
  else if(i==1){
    	ans=abs(h[1]-h[0]);
   		 memo[1]=ans;
    	mem[1]=true;
  }
    else{
        ans=min(memo[i-2]+abs(h[i]-h[i-2]),memo[i-1]+abs(h[i]-h[i-1]));
        memo[i]=ans;
		mem[i]=true;
    }
  return ans;
}
int main(void) {
  	cin>>N;
    mem[0]=true;
    rep(i, N) {
        cin >> h[i];
        }
  	vector<int>ans(N);
  		rep(i,N){
          ans[i]=DFS(i);
         if(i==N-1){
			cout<<ans[i]<<endl;
         }
        }
}
