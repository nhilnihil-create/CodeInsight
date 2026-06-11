 #include<bits/stdc++.h>
using namespace std;
int main()
  {
  char ch[3];
  cin>>ch;
  for(int i = 0;i<3;i++)
  {
    if(ch[i]=='9')
       ch[i] = '1';
    else if(ch[i]=='1')
       ch[i] = '9';
  }
  
  cout<<ch<<endl;
  }