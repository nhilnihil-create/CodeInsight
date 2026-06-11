#include <bits/stdc++.h>
using namespace std;

int main()
{
       int x;cin>>x;
       long long y;
       vector<int>v;
       v.push_back(1);
       for(long long i=2;i*i<=x;i++)
       {
           y=i*i;
           if(y<=x)
            v.push_back(y);
           while(y*i<=x){
            v.push_back(y*i);
            y*=i;
           }
       }
      sort(v.begin(),v.end());
       cout<<v[v.size()-1];
    return 0;
   }