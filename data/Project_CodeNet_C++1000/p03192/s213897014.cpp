 #include<bits/stdc++.h>
using namespace std;
int main()
{ 
  char ch[10000];
  int count = 0;
  cin>>ch;
  for(int i = 0;i<4;i++)
  {
    if(ch[i]=='2')
    count++;
  }
  cout<<count<<endl;
}
