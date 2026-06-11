#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}
int gcd_arr(vector<int> &a){
  int n = a.size();
  for(int i=n-2; i>=0; i--){
    a[i] = gcd(a[i], a[i+1]);
  }
  return a.front();
}

int main(void){
    long long int i=0,j,h,c=0,n,m,x[100000],dp[100000],ans=0;
    string s;
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> x[i];
    }
    sort(x,x+m);
    for(i=0;i<m-1;i++)
    {
        dp[i]=abs(x[i]-x[i+1]);   
    }
    sort(dp,dp+m-1);
    for(i=0;i<m-n;i++)
    {
        ans+=dp[i];
    }
    cout << ans << endl;
    return 0;
}
