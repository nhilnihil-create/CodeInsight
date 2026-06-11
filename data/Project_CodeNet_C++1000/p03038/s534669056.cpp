#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare( pair<ll,ll> a , pair<ll,ll> b)
{
    return a.second > b.second  ;
}
int main()
{
   ll n,m;
   cin>>n>>m;
   priority_queue<int , vector<int> , greater<int> > q;
   for(int i=0;i<n;i++)
   {
       ll temp;
       cin>>temp;
       q.push( temp  );
   }
   auto* arr = new pair<ll , ll> [m];
   for(int i=0;i<m;i++)
   {
       cin>>arr[i].first >>arr[i].second ;
   }
   sort( arr , arr + m , compare );

   int index = 0;
   while( index < m )
   {
       ll amount = arr[index].first ;
       ll val = arr[index].second;
       if( val > q.top() )
       {
           while( q.top() < val && amount > 0 )
           {
               q.pop();
               q.push(val);
               amount--;
           }
       }
       index++;
   }
   ll sum =0;
   while( !q.empty() )
   {
       sum += q.top();
       q.pop();
   }
   cout<<sum;
}