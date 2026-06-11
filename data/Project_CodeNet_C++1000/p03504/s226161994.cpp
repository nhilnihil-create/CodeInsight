#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  int N, C;cin>>N>>C;
  vector<pair<P, int>> program(N);
  rep(i, N){
  	int s, t, c;cin>>s>>t>>c;
    program[i]=make_pair(P(t, s), --c);
  }
  sort(program.begin(), program.end());
  rep(i, C){
    int j_=-1;
  	rep(j, N){
      if(program[j].second!=i)continue;
      if(j_==-1){j_=j;continue;}
      if(program[j_].first.first==program[j].first.second){
      	program[j]=make_pair(
          P(program[j].first.first, program[j_].first.second), i
        );
        program[j_]=make_pair(P(-1, -1), -1);
      }
      j_=j;
    }
  }
  int MAX_T = 100002;
  vector<int> r(MAX_T, 0), rr(MAX_T);
  rep(i, N){
    if(program[i].second==-1)continue;
    r[program[i].first.first]--;
    r[program[i].first.second-1]++;
    // cout<<program[i].first.second-1<<" "<<program[i].first.first<<endl;
  }
  rr[0]=r[0];
  int ans=-1;
  repb(t, 1, MAX_T){
    rr[t] = rr[t-1]+r[t];
    ans=max(ans, rr[t]);
  }
  cout<<ans<<endl;
  return 0;
}

