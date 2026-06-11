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

int main(void){
   string S;
   cin>>S;
   bool flag=false;
   int N=S.size();
   for(int i=0;i<=N;i++){
      for(int j=1;j<=N-i;j++){
         string temp=S.substr(0,i)+S.substr(N-j,j);
         if(temp=="keyence"){
            flag=true;
         }
      }
   }
   if(flag) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   return 0;
}
