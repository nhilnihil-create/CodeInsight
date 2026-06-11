#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define    ll   long long int
#define    py   printf("Yes\n")
#define    pn   printf("No\n")
#define    in   cin>>
using namespace std;

ll hako[200000];
int main()
{
  int n,t,tmp=1001,count=0;
  int i=0;
  in n>>t;
  int c[n];
  int hoge[n];
  for(;i<n;i++){
    in c[i];
    in hoge[i];
    if(t>=hoge[i]){
      if(tmp>c[i])tmp=c[i];
    }
    else count++;
  }
  if(count==i)cout<<"TLE"<<endl;
  else cout<<tmp<<endl;
}
