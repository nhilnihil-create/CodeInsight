#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int INF = 1e9;
inline int read(){
	int X = 0,w = 0 ;
	char ch = 0;
	while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}
	while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
	return w ? -X : X;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    vector<int> c,d;
    int ans=0;
    int pow_2=1;
    for(int i=0;i<=28;i++)
    {
        c=a;
        d=b;
        for(int j=0;j<n;j++)
        {
            c[j]%=2*pow_2;
            d[j]%=2*pow_2;
        }
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        int l,r;
        int sum=0;
        for(int j=0;j<n;j++)
        {
            l=lower_bound(d.begin(),d.end(),pow_2-c[j])-d.begin();
            r=lower_bound(d.begin(),d.end(),2*pow_2-c[j])-d.begin()-1;
            sum+=(r-l+1);
            l=lower_bound(d.begin(),d.end(),3*pow_2-c[j])-d.begin();
            r=lower_bound(d.begin(),d.end(),4*pow_2-c[j])-d.begin()-1;
            sum+=(r-l+1);
        }
        if(sum&1)
        {
            ans+=pow_2;
        }
        pow_2*=2;
    }
    cout<<ans<<endl;
    return 0;
}