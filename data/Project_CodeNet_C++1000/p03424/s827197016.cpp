#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ll x;
//    x=1ll << 59;
//    ll y=(1ll << 59) - 1ll;
//    cout<<((double)(x)==(double)(x-1))<<endl;
    ll n;
    cin>>n;
    char l1[n+1];
    set<char>s;
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        s.insert(l1[i]);
    }
    if(s.size()==3)cout<<"Three";
    else cout<<"Four";
}
