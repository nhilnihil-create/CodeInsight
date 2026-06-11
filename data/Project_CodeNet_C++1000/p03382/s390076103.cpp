#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    int N; cin>>N;
    vint a(N);
    REP(i,N) cin>>a[i];

    sort(ALL(a));
    int x=a[N-1],y=a[0];
    REP(i,N-1){
        if(abs(2*a[i]-x)<abs(2*y-x)) y=a[i];
    }
    cout<<x<<' '<<y<<endl;

}
