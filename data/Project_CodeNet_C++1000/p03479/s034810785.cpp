#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000007
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


bool bet(int i , int a ,int b)
{
     int sum =0;

     while(i)
     {
         sum+=i%10;
         i/=10;
     }
     if(sum<a||sum>b)
        return false;
     return true;
}
int main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
ll x,y;
cin>>x>>y;

int ans =1;
int  mult = 2;
while(x*mult<=y)
{
x=x*mult;
ans++;
}
cout<<ans<<endl;
 return 0;
}
