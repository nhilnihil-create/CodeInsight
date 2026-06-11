#include<bits/stdc++.h>
using namespace std;

#define int long long int 

const int  dx[]={0,0,1,1,1,-1,-1,-1};
const int  dy[]={-1,1,0,1,-1,-1,0,1};

int32_t main()
{
  int h,w;
  cin>>h>>w;
  vector<string> str;
  for(int i=0;i<h;i++)
  {
    string s;
    cin>>s;
    str.push_back(s);
  }

  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
       if(str[i][j]!='.')
       continue;
        int ans=0;
        //cout<<"psia "<<i<<" "<<j<<endl;
       for(int k=0;k<8;k++)
       {
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<h && y>=0 && y<w && str[x][y]=='#')ans++; 
       }
       str[i][j]=char(ans+'0');
    }
  }
  for(auto i:str)
  cout<<i<<endl;

}