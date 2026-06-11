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
  int n;
  in n;
  bool flag=true;
  int ans=0;
  int i=1;
  while(flag==true){
    ans=111*i;
    if(n<=ans){
      flag=false;
    }
    i++;
  }
  cout<<ans<<endl;
}
