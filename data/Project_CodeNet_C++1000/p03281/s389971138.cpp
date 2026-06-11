#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,ans=0;
  cin >> n;
  for(int i =1;i<=n;i++){
    int a=0;
     for(int j =1;j<=i;j++){
      if(i%j==0&&i%2!=0)
      {
        a+=1;
      }
    }
     if(a==8)ans++;
  }
  cout <<ans;
}
