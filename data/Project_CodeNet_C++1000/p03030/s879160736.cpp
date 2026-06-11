#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare( pair<int,int> a , pair<int,int> b)
{
    return a.second > b.second;
}

int main()
{
   int n;
   cin>>n;
   map<string , vector<pair<int,int>> > m;

   for(int i=1;i<=n;i++)
   {
       string city;
       cin>>city;
       int rating;
       cin>>rating;
       m[city].push_back( make_pair(i,rating ) );
   }
   auto it = m.begin();
   vector<string> cities;
   while( it!= m.end())
   {
       cities.push_back(it->first);
       it++;
   }
   sort( cities.begin() , cities.end() );
    for(int i=0;i<cities.size() ;i++)
    {
       sort(  m[cities[i]].begin() ,m[cities[i]].end() , compare );
       for(int j=0;j<m[cities[i]].size() ;j++)
       {
           cout<<m[ cities[i] ][j].first<<endl;
       }
    }

}