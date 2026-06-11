#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N;
 cin>>N;
 int v[30];
 int c[30];
 int ans=0;
 for(int i=0;i<N;i++){
    cin>>v[i];
 }
 for(int i=0;i<N;i++){
    cin>>c[i];
 }
 for(int i=0;i<N;i++){
    if(v[i]-c[i]>0){ans+=v[i]-c[i];}
 }
 cout<<ans<<endl;
 return 0;}