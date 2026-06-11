#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    vector<int> x;
    if(n%2==0)x.push_back(0);
    else{
        x.push_back(1);
        n--;
    }
    n/=(-2);
    while(n!=(ll)0){
        if(n%2==0)x.push_back(0);
        else{
            x.push_back(1);
            n--;
        }
        n/=(-2);
    }
    reverse(x.begin(),x.end());
    rep(i,x.size()) cout<<x[i];
    cout<<endl;
}

