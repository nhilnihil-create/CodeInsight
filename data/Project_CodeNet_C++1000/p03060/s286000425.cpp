#include<bits/stdc++.h>

#define _fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pi acos(-1)
#define MAXS 100000
#define MOD 998244353
#define all(v) v.begin(),v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int tc;


void sol()
{

    int n,c,g=0,s=0,a[105];
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int j=1; j<=n; j++){
        cin>>c;
        if(c<a[j]){
            g+=a[j];
            s+=c;
        }
    }
    cout<<g-s<<endl;


}

int main()
{

    _fastIO;

    //cin>>tc;while(tc--)
    sol();

    return 0;
}
