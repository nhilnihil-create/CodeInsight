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

    ll l1[6],x=0,s=0;
    for(int i=1;i<=5;i++){
        cin>>l1[i];
        s+=l1[i]+((l1[i]%10)!=0?10-(l1[i]%10):0);
        if((l1[i]%10)!=0)x=max(x,(ll)(10-(l1[i]%10)));
    }
    cout<<s-x<<endl;
}
