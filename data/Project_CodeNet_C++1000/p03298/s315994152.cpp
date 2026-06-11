#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;cin>>N;
  vector<tuple<int,string,string>> front;
  vector<tuple<int,string,string>> back;
  string S;cin>>S;long long count=0;
  for(int i=0;i<(1<<N);i++)
  {
  	string red,blue;
    int countred=0;
    for(int j=0;j<N;j++)if(i&(1<<j)){red+=S[j];countred++;}
    else blue=S[j]+blue;
    front.push_back({countred,red,blue});
  }
  for(int i=0;i<(1<<N);i++)
  {
  	string red,blue;
    int countred=0;
    for(int j=0;j<N;j++)if(i&(1<<j)){red+=S[N+j];countred++;}
    else blue=S[N+j]+blue;
    back.push_back({N-countred,blue,red});
  }
  sort(front.begin(),front.end());
  sort(back.begin(),back.end());
  long long i=0,j=0;
  while(i<front.size()&&j<back.size())
  {
    if(front[i]>back[j])j++;
    else if(front[i]<back[j])i++;
    else 
    {
      long long counti=1,countj=1;
      while(i+1<front.size())if(front[i+1]==front[i]){i++;counti++;}else break;
      while(j+1<back.size())if(back[j+1]==back[j]){j++;countj++;}else break;
      count+=(counti*countj);
      i++;
    }
  }
  cout<<count<<endl;
}