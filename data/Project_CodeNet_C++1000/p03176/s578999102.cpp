#include<bits/stdc++.h>
using namespace std;
long long int dp[200005];
int n;
long long int a[200005], h[200005];

void insert(int x, long long int val){
      //cout<<x<<' ';
      int index=x;
      //cout<<index<<' '<<val<<'\n';
      while(index<=n){
            if(dp[index]<val){
                  dp[index]=val;
            }
            else break;
            //cout<<index<<' ';
            int p=index&(-index);
            //cout<<index<<' ';
            index+=p;
            //cout<<p<<'p'<<index<<' ';
      }
      //cout<<'\n';
      //cout<<'\n'<<' '<<x<<'a'<<'\n';
}

long long int get(int x){
      int index=x;
      long long int val=0;
      while(index>0){
            val=max(val, dp[index]);
            index-=(index&(-index));
      }
      return val;
}

int main(){
      cin>>n;
      memset(dp, 0, sizeof(dp));
      for(int i=0; i<n; i++){
            cin>>h[i];
      }
      for(int i=0; i<n; i++){
            cin>>a[i];
      }
      long long int curr, prev;
      for(int i=0; i<n; i++){
            prev=get(h[i]-1);
            curr=get(h[i]);
            //cout<<prev<<' ';
            if(prev+a[i]>curr){
                  //cout<<a[i]<<' ';
                  insert(h[i], prev+a[i]);
                  //cout<<prev+a[i]<<' '<<i<<'\n';
            }
      }
      //for(int i=0; i<=n; i++)
      //cout<<get(n)<<'\n';
      cout<<get(n);
}