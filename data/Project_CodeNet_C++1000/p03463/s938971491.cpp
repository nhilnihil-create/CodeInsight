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
   int N,A,B;
   cin>>N>>A>>B;
   if((B-A)%2==0){
      cout<<"Alice"<<endl;
   }else if((B-A)%2==1){
      cout<<"Borys"<<endl;
   }else if(A==B){
      cout<<"Draw"<<endl;
   }
   return 0;
}
