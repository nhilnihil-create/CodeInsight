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

int n ,k;
cin>>n>>k;

map<int,int> m;
for(int index = 0 ;index < n;index++)
{
    int a ;
    cin>>a;
    m[a]++;
}
vector<int> s;
for(auto it = m.begin();it!=m.end();it++)
    s.push_back(it->second);

sort(s.begin(),s.end());


int ans = 0;
if(s.size()>=k)
for(int index = 0 ;index <s.size()-k;index++)
    ans+=s[index];

    cout<<ans<<endl;

 return 0;
}
