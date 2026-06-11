#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double d;

#define tt int t; cin>>t; while(t--)
#define lo(i, a, b) for(int i=a; i<b; i++)
#define rlo(i, a) for(int i=a; i>=0; i--)

#define be(a) a.begin(),a.end()
#define sz(x) x.size()

#define sp " "
#define nl cout<<'\n';
#define su ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main()
{
    su;
    string c,d;
    cin>>c>>d;
    reverse(be(d));
    if(c==d)
      cout<<"YES";
    else
      cout<<"NO";
    nl;
    return 0;
}
