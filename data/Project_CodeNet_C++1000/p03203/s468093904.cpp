#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
pair<int,int> P[1<<18];
main(){int H,W,N;cin>>H>>W>>N;for(int i=0;i<N;++i)cin>>P[i].f>>P[i].s;sort(P,P+N);
for(int i=0,c=0;i<N;++i){
if(P[i].s+c<P[i].f){cout<<P[i].f-1;return 0;}
if(P[i].s+c==P[i].f)++c;}
cout<<H;}