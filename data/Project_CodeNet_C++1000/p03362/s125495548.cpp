#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int pn[55]={11,31,41,61,71,101,131,151,181,191,
            211,241,251,271,281,311,331,401,421,431,
            461,491,521,541,571,601,631,641,661,691,
            701,751,761,811,821,881,911,941,971,991,
            1021,1031,1051,1061,1091,1151,1171,1181,1201,1231,
            1291,1301,1321,1361,1381
            };
int main(void){
    int n;cin>>n;
    rep(i,n)cout<<pn[i]<<" ";
    cout<<endl;
}
