#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;

bool sort_sec(const pair<int,int> &a,const pair<int,int> &b){
   if(a.second<b.second){
      return true;
   }
   return false;
}

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}

int main(void){
   long long K,A,B;
   cin>>K>>A>>B;
   long long ans=1;
   long long money=0;
   long long temp=0;
   while(1){
      if(temp==K) break;
      if(money>=1){
         ans+=B*money;
         money--;
      }else{
         if(ans>=A&&(K-temp)>1){
            ans=ans-A;
            money++;
         }else{
            ans++;
         }
      }
      temp++;
   }
   cout<<max(1+K,ans)<<endl;
   return 0;
}