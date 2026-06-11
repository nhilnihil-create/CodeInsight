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
   int R,G,B,N;
   cin>>R>>G>>B>>N;
   long long ans=0;
   for(int i=0;i<=3000;i++){
      for(int j=0;j<=3000;j++){
         int temp=N-R*i-G*j;
         if(0<=temp&&temp%B==0) ans++;
      }
   }
   cout<<ans<<endl;
   return 0;
}
