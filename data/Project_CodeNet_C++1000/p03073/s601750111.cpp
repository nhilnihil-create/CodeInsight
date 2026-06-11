#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    char c='2';
    string s;
    cin>>s;
    int ans=0;
    rep(i,s.length()){
        if(i==0)continue;
        if(s[i]==s[i-1]){
            if(s[i]=='1')s[i]='0';
            else s[i]='1';
            ans++;
        }
    }
    cout<<ans<<endl;
}
