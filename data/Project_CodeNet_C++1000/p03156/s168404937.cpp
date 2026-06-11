#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   int A,B;
   cin>>A>>B;
   vector<int> P(N);
   for(int i=0;i<N;i++){
      cin>>P[i];
   }
   int result[3]={0};
   for(int i=0;i<N;i++){
      if(P[i]<=A) result[0]++;
      else if(A+1<=P[i]&&P[i]<=B) result[1]++;
      else result[2]++;
   }
   cout<<min(result[0],min(result[1],result[2]))<<endl;
   return 0;
}
