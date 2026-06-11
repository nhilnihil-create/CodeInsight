#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

int main(){
    ll N,cn=0,A=0,B=0,BA=0;cin>>N;
    string s[10010];
    rep(i,0,N){
        cin>>s[i];
        rep(j,0,s[i].size()-1){
            if(s[i].at(j)=='A'&&s[i].at(j+1)=='B')cn++;
        }
        if(s[i].at(0)=='B'&&s[i].at(s[i].size()-1)=='A')BA++;
        else if(s[i].at(0)=='B')B++;
        else if(s[i].at(s[i].size()-1)=='A')A++;
    }
    if(BA!=0&&B==0&&A==0)cn+=BA-1;
    else cn+=min(BA+A,BA+B);
    cout<<cn<<endl;
}





