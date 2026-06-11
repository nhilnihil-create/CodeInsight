#include<bits/stdc++.h>
#include<tuple>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a=20000000;
    string s;
    cin>>s;
    for(int i=0;i<s.size()-3+1;i++){
        ll b=stoi(s.substr(i,3));
        a=min(a,abs(b-753));
    }
    cout<<a;
}
