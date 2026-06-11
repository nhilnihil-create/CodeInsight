#include <bits/stdc++.h>
using namespace std;


int main() {
long N,K;
cin>>N>>K;
vector<long> v(N);
for(int i=0;i<N;i++) cin>>v[i];
long ans=0;
for(int i=0;i<=K;i++){
  for(int j=0;j<=K-i;j++){
    int k=K-i-j;
    if(i+j>N) continue;
    if(k<0) continue;

    priority_queue<long> q;
    for(int a=0;a<i;a++) q.push(-v[a]);
    for(int a=0;a<j;a++) q.push(-v[N-1-a]);
    int now=0;
    while(!q.empty()&&now<k){
      long t=q.top();
      if(t<0) break;
      q.pop();
      now++;
    }
    long tmp=0;
    while(!q.empty()){
      long t=q.top();
      tmp+= -t;
      q.pop();

  }
  
  ans=max(tmp,ans);
}

}
cout<<ans<<endl;
}
