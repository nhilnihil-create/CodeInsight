#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main(){
 int D,N;
 cin>>D>>N;
 int count=0;
 for(int i=1;;i++){
   int counti=0;int k=i;
   while(k!=0){if(k%100!=0){break;}
   else{k/=100;counti++;}
 }
 if(D==counti){
   count++;
   if(count==N){
     cout<<i<<endl;
     return 0;
   }
 }
 }
  
 return 0;
}