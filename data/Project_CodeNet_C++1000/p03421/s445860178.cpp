#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll k=1,n,a,b;cin>>n>>a>>b;
    if(n<a+b-1 || n>a*b)return cout<<"-1" , 0;
    vector<ll> arr;
    for(ll i=0;i<a;i++){
        for(ll j=0;j<b && a-i-1+k<=n;j++)arr.push_back(k++);
        while(!arr.empty())cout<<arr.back()<<" ",arr.pop_back();
    }
}