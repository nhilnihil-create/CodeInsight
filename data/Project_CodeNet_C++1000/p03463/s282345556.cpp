#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
using namespace std;


int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<((b-a)%2==0? "Alice":"Borys")<<endl;
    return 0;
}