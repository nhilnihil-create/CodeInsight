#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N;
   string S;
   cin>>N>>S;
   map<char,int> dataA;
   map<char,int> dataB;
   int maxC=0;
   rep(i,N-1){
       int cnt=0;
       dataA.clear();
       dataB.clear();
       rep(j,i+1){
           dataA[S[j]]++;
       }
       rep(k,N-i-1){
           dataB[S[N-k-1]]++;
       }
       
       for(auto mapA : dataA){
           auto K=mapA.first;
           
           if(dataB.count(K)){
               cnt++;
           }
       }
       maxC=max(maxC,cnt);
   }
   cout<<maxC<<endl;
 
}