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


int main()
{
ll n ;
cin>>n;
if(n==1)
    cout<<"1"<<endl;
else
{
    ll now = 1, prev = 2;
    for(ll index = 3 ;index <=n+1;index++)
    {
        ll c = now;
        now+=prev;
        prev=c;
    }

    cout<<now<<endl;
}

 return 0;
}
