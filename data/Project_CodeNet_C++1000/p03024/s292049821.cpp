#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s;
    int ans=0;
    cin>>s;
    rep(i,s.length()){
        if(s[i]=='o')ans++;
    }
    cout<<((ans+15-s.length()>=8)?"YES":"NO")<<endl;
}
