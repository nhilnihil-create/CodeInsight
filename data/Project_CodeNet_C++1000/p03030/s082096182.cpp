#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

bool sortby2(pair<pair<string,int>,int> &a, pair<pair<string,int>,int> &b)
{
   if(a.first.first == b.first.first)
      return a.first.second > b.first.second;
   return (a.first.first < b.first.first);
}

int main()
{
   int n;
   cin>>n;
   vector<pair<pair<string, int>,int>> v(n);
   for(int i=0;i<n;i++)
   {
      cin>>v[i].first.first;
      cin>>v[i].first.second;
      v[i].second = i+1;
   }

   sort(v.begin(), v.end(), sortby2);
   for (auto i = v.begin(); i !=v.end(); i++)
   {
      cout<<(*i).second<<endl;
   }
   
   return 0;
}
