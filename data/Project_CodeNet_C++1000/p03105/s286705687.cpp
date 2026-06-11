#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.begin(), a.end())
using namespace std;
#define m 1000000007

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c; cin>>a>>b>>c;
    cout<<min(c, b/a);
    return 0;
}