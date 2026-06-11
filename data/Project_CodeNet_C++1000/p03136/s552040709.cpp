 #include<bits/stdc++.h>
using namespace std;
int main()
{ 
  int n,sum = 0;
  cin>>n;
  int a[n];
  for(int i = 0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  
  for(int i = 0;i<n-1;i++)
  {
    sum = sum + a[i];
  }
  
  if(a[n-1]<sum)
  cout<<"Yes"<<endl;
  else if(a[n-1]>=sum)
  cout<<"No"<<endl;
}
