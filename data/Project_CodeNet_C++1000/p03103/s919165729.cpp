#include<bits/stdc++.h>

using namespace std;

int main() {

int N,M;
cin>>N>>M;
vector<int> a(N);
vector<int> b(N);
for(int i=0;i<N;i++)
{
   cin>>a[i]>>b[i];
   
}
vector<pair<int,int>> AB(N);
for(int i=0;i<N;i++){
   AB[i]=make_pair(a[i],b[i]);
}
sort(AB.begin(),AB.end());
long long ans=0;
for(int i=0;i<N;i++){
int b=min(M,AB[i].second);
ans+=(long long)b*AB[i].first;
M-=b;
}
cout<<ans<<endl;
   return 0;
}




