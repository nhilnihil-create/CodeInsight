#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s,t="keyence";
    cin>>s;
    int ans=0,first;
    for(i=0;i<s.length();i++){
        if(s[i]!=t[i]){
            cerr<<i<<endl;
            break;
        }
    }
    cout<<(s.substr(s.length()-7+i,7-i)==t.substr(i,7-i)?"YES":"NO")<<endl;
}