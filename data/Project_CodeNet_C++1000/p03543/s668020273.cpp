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
string s ;
cin>>s;

if((s[1]!=s[0]&&s[1]!=s[3])||s[1]!=s[2])
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;
 return 0;
}
