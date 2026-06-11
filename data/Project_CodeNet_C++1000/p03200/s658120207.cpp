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

int gcd(int a,int b){
   if(a%b==0) return b;
   return gcd(b,a%b);
}
int digit(int num){
   int cnt=0;
   while(num!=0){
      cnt+=num%10;
      num=num/10;
   }
   return cnt;
}
int main(void){
   string S;
   cin>>S;
   int N=S.size();
   long long ans=0;
   int cnt_B=0;
   for(int i=0;i<N;i++){
      if(S[i]=='B'){
         cnt_B++;
      }else{
         ans+=cnt_B;
      }
   }
   cout<<ans<<endl;
   return 0;
}
