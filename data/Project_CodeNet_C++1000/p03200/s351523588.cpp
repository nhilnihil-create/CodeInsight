#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    string s;
    cin>>s;
    long long ans=0,cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='W'){
            ans=ans+cnt;
        }
        else cnt++;
    }   
    cout<<ans;
}

