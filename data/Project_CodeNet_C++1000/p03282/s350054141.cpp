#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int ctoi(const char c){
    if('0'<=c && c<='9') return (c-'0');
    else return -1;
}

int main(){
    string s;
    long long int k;
    cin>>s>>k;
    int ans=1;
    int count=0;
    rep(i,s.size()){
        if(s[i]!='1'){
            ans=ctoi(s[i]);
            break;
        }
        else count+=1;
    }
    if(count<k)cout<<ans<<endl;
    else cout<<1<<endl;
}