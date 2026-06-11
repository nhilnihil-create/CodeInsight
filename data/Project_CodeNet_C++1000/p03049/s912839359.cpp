#include <bits/stdc++.h>
#define ll long long
const ll MOD=1e9+7;
using namespace std;

int main(){
    ll N,AB=0,A=0,B=0,cnt=0;
    cin>>N;
    for(ll i=0;i<N;i++){
        string s;
        cin>>s;
        ll a=s.size();
        for(ll j=0;j+1<a;j++){
            if(s[j]=='A'&&s[j+1]=='B') cnt++;
        }
        if(s[0]=='B'&&s[a-1]=='A') AB++;
        else if(s[0]=='B') B++;
        else if(s[a-1]=='A') A++;
    }
    if(A!=0||B!=0) cnt+=min(A,B)+AB;
    else if(AB>0)cnt+=AB-1;
    cout<<cnt<<endl;
}