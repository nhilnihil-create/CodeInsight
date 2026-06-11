#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s;
    cin>>s;
    int ans=0;
    rep(i,s.length()){
        if(s[i]=='2')ans++;
    }
    cout<<ans<<endl;
}