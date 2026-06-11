#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    ans+= min((a+b+1),c);
    ans+=b;
    cout<<ans;

}
