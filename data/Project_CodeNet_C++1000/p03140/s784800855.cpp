#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
using namespace std;


int main(){
    int n,d=0;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    rep(i,n){
        if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) d += 2;
        else if(a[i]==b[i] && b[i] != c[i]) d += 1;
        else if(a[i]==c[i] && a[i] != b[i]) d += 1;
        else if(c[i]==b[i] && a[i] != c[i]) d += 1;
    }
    cout<<d<<endl;
    return 0;
}