 #include<bits/stdc++.h>
using namespace std;
int main()
  {
  int n,h,w,ans=0;
  cin>>n>>h>>w;
  int a[n],b[n];
  for(int i=0;i<n;i++)
    {
    cin>>a[i]>>b[i];
    if(h<=a[i]&&w<=b[i])
      ans++;
    }
  cout<<ans<<endl;
  }
