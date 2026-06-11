#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

signed main(){

    lli a,b,c,d;
    cin>>a>>b>>c>>d;

    if(abs(a-c)<=d || ((abs(a-b)<=d) && (abs(b-c)<=d)))
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

	return 0;
}