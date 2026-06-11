#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const int INF=1<<17;

int main(){
    string s;
    cin >> s;
    int a[3]={};
    for(int i=0;i<s.length();i++){
        a[s[i]-'a']++;
    }
    if(max({a[0],a[1],a[2]})-min({a[0],a[1],a[2]})<=1) puts("YES");
    else puts("NO");
    return 0;
}