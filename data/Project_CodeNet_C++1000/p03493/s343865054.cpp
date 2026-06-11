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



int main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);

int n;
cin>>n;

int ans = 0 ;
while(n)
{
    ans +=n%10;
    n/=10;
}
cout<<ans<<endl;
 return 0;
}
