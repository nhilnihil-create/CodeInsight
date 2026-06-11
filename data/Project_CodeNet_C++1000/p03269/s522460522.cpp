#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b;++i)
#define fdto(i,a,b) for(int i=a; i>=b;--i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define maxn 100009
#define gb(i,j) ((i>>j)&1)
#define name "a"
#define endl '\n'

using namespace std;

int n,m,L,a[100],b[100],c[100];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> L;
    --L;
    n=20;
    fto(i,2,n){
        ++m;
        a[m]=i-1;
        b[m]=i;
        c[m]=0;
    }
    int t=log2(L);
    fto(i,0,t-1){
        ++m;
        a[m]=20-i-1;
        b[m]=20-i;
        c[m]=(1<<i);
    }
    int tg=(1<<t);
    for(int i=t-1; i>=0; --i)
    if(gb(L,i)){
        ++m;
        a[m]=1;
        b[m]=20-i;
        c[m]=tg;
        tg+=(1<<i);
    }
    ++m;
    a[m]=1;
    b[m]=20;
    c[m]=tg;
    cout << n <<' '<<m <<endl;
    fto(i,1,m) cout << a[i] << ' '<< b[i] <<' '<< c[i]<<endl;
    return 0;
}
