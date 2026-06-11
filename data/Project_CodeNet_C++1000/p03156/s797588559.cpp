#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int n,a,b;
  cin>>n>>a>>b;
  vector<int> p1,p2,p3;
  REP(i,n){
    int p;
    cin>>p;
    if(p<=a) p1.emplace_back(p);
    else if(p<=b) p2.emplace_back(p);
    else p3.emplace_back(p);
  }
  cout<<min(min(p1.size(),p2.size()),p3.size())<<endl;
  
	return 0;
}