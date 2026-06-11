#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007 //10^9+7
#define div 998244353
#define rep(i,n) for(int i=0;i<n;i++)
string s;
bool ans=false;
string c[]={"KIHBR","AKIHBR","KIHABR","AKIHABR","KIHBAR","AKIHBAR","KIHABAR","AKIHABAR","KIHBRA","AKIHBRA","KIHABRA","AKIHABRA","KIHBARA","AKIHBARA","KIHABARA","AKIHABARA"};
signed main(){
    cin>>s;
    rep(i,16){
        if(s==c[i])ans=true;
    }
    if(ans)puts("YES");
    else puts("NO");
    return 0;
}
