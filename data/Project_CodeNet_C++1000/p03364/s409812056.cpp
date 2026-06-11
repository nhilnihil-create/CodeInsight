#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<random>
#include<stdio.h>
using namespace std;

typedef long long ll;

int main(){
 int N;
 cin>>N;
 vector<string> S(N);
 for (int i=0;i<N;i++){
     cin>>S[i];
 }
 int ans=0;
 for (int i=0;i<N;i++){
     int A=i;
     int B=0;
     int flag=0;
     for (int j=0;j<N;j++){
         for (int k=0;k<N;k++){
             if (S[(j+A)%N][(k+B)%N]!=S[(k+A)%N][(j+B)%N]){
                 flag=1;
             }
         }
     }
     if (flag==0){
         ans+=N;
     }
 }
 cout<<ans<<endl;
}