#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    string s;
    cin>>s;
    int num[3]={0};
    rep(i,s.size()) num[s[i]-'a']++;
    sort(num,num+3);
    if(num[2]-num[0]<=1) cout<<"YES";
    else cout<<"NO";
}