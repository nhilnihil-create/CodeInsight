#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    ll sum=0,k=s.length();
    for(ll i=0;i<k;i++)
    if(s[i]=='o')
    sum++;
    if(sum+15-k>=8)
    cout<<"YES";
    else
    cout<<"NO";
}
