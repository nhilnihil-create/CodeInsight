#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N,M;
cin>>N>>M;
vector<int>l(M);
vector<int>r(M);
int maxx=0;
int minn=1000000;
for(int i=0;i<M;i++){
   cin>>l[i]>>r[i];
   maxx=max(maxx,l[i]);
   minn=min(minn,r[i]);
}
int a=0;
for(int i=1;i<=N;i++){
   if(maxx<=i&&i<=minn){
      a++;
   }
}
cout<<a<<endl;


return 0;
}
