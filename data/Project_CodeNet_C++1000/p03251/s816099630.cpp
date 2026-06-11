#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int N,M,X,Y,l,r;
   cin >> N >> M >> X >> Y;
   int data_X[N];
   int data_Y[M];
   
   for(int i=0;i<N;i++) cin >> data_X[i];
   for(int i=0;i<M;i++) cin >> data_Y[i];
   
   sort(data_X,data_X+N,greater<int>());
   sort(data_Y,data_Y+M);
   
   l = data_X[0];
   r = data_Y[0];
   
   for(int i=l+1;i<=r;i++){
       if(X < i && i <= Y){
           cout << "No War" << endl;
           return 0;
       }
   }
   
   cout << "War" << endl;
}