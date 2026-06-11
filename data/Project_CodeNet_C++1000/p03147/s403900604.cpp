#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int N;
   cin>>N;
   vector<int>h(N);
   for(int i=0;i<N;i++){
      cin>>h[i];
   }
   int count=0;
   while(true){
      if(*max_element(h.begin(),h.end())==0){break;}
      int i=0;
      while(i<N){
         if(h[i]==0){i++;}
         else{
            count++;
            while(i<N&&h[i]>0){
               h[i]--;
               i++;
            }
         }
      }
   }
   cout<<count<<endl;
return 0;}