#include <bits/stdc++.h>
using namespace std;
void fast(){
cin.tie(0);
cin.sync_with_stdio(0);
}
int main()
{
    fast();
 int r,c;
 cin>>r>>c; int a[r][c]={};vector < pair< int ,int> > v; pair<int,int>b;int x;
 for(int i=0;i<r;i++)
 {
     for(int j=0;j<c;j++)
     {
         cin>>x;
         a[i][j]+=x;
         if(a[i][j]%2!=0)
         {
            if(j<c-1){a[i][j+1]++;b.first=i+1;b.second=j+1;v.push_back(b);b.first=i+1;b.second=j+2;v.push_back(b);}
             else if(i<r-1){a[i+1][j]++;b.first=i+1;b.second=j+1;v.push_back(b);b.first=i+2;b.second=j+1;v.push_back(b);}
         }
     }
 }
 cout<<v.size()/2<<endl;
 for(int i=0;i<v.size();i+=2)
 {
     cout<<v[i].first<<" "<<v[i].second<<" "<<v[i+1].first<<" "<<v[i+1].second<<endl;
 }
 return 0;
}
