#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
int compare(pair<string,pair<int,int>>p1,pair<string,pair<int,int>>p2)
{


    if(p1.first==p2.first)
    {
        return p1.second.first>p2.second.first;

    }
    return p1<p2;




}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 int n;
 cin>>n;
 vector<pair<string,pair<int,int>>>v(n);
  for(int i=0;i<n;i++)
  {
      string name;
      int point;
      cin>>name>>point;
      v[i]=(make_pair(name,make_pair(point,i+1)));

  }

 sort(v.begin(),v.end(),compare);

  for(int i=0;i<v.size();i++)
  {
      cout<<v[i].second.second<<endl;
  }






}