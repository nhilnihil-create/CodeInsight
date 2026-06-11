#include <bits/stdc++.h>
using namespace std;

int N,M,X,a[1010],Kiri=0,Kanan=0;
int main(){
    cin>>N>>M>>X;
    for(int i=1;i<=M;i++){
        cin>>a[i];
    }
   for(int i=1;i<=M;i++){
       if(1<=a[i]&&a[i]<=X){
           Kiri++;
       }
       else if(X<=a[i]&&a[i]<=N){
           Kanan++;
       }
       
   }
   cout<<min(Kiri,Kanan);
}