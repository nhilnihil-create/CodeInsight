/*
/ ATcoder /
ID : lalit kumar
TASK : A
LANG : c++14
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

ll a,b,k;
cin>>a>>b>>k;
if(k>(b-a)+1)
{
    for(int i = a;i<=b;i++)
    {
        cout<<i<<endl;
    }
   return 0 ;
}
set<ll> s;
for(int i =a;i<a+k;i++) s.insert(i);
for(int i = b;i>b-k;i--) s.insert(i);
for(auto x:s) if(x>0) cout<<x<<endl;

 return 0;

}