 #include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  char ch[n];
  cin>>ch;
  for(int i =0;i<n;i++)
  {
    if(i==(k-1))
    ch[i] = tolower(ch[i]);
  }
  cout<<ch<<endl;
}