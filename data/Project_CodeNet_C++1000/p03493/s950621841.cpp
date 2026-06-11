 #include<bits/stdc++.h>
using namespace std;
int main()
  {
     char ch[3];
     int count = 0;
     cin>>ch;
     for(int i = 0;i<3;i++)
     {
       if(ch[i]=='1')
       count++;
     }
     cout<<count<<endl;
  } 