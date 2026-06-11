#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;cin>>N;
  tuple<int,int,int> txy[N];
  for(int t,x,y,i=0;i<N;i++)
  {
    cin>>t>>x>>y;
    txy[i]={t,x,y};
    if(x+y>t||(t-x-y)%2==1){cout<<"No"<<endl;return 0;}
    if(i>0)if(t-get<0>(txy[i-1])<abs(x-get<1>(txy[i-1]))+abs(y-get<2>(txy[i-1]))||(t-get<0>(txy[i-1])-abs(x-get<1>(txy[i-1]))-abs(y-get<2>(txy[i-1])))%2==1){cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
}