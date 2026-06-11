#include<bits/stdc++.h>

using namespace std;

int main() {
int N,K;
cin>>N>>K;
vector<int>h(N);
for(int i=0;i<N;i++){
   cin>>h[i];
}
sort(h.begin(),h.end());
int minn=1000000000;
int a;
for(int i=0;i<=N-K;i++){
   a=h[i+K-1]-h[i];
   minn=min(minn,a);
}
cout<<minn<<endl;

   return 0;
}




