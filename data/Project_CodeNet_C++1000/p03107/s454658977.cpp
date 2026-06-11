/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll noo=0,noz=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')noz++;
        else noo++;
    }
    cout<<2ll*min(noo,noz);
}
