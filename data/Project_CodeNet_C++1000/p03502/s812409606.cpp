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

int b = n;
int sum = 0;
while(n)
{
    sum+=n%10;
    n/=10;
}

if(b%sum)
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;

 return 0;
}
