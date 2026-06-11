/**
题意:给定目标串S(由小写字母构成),统计取出S的字符组成的不同串的个数;
define ：不同串:
              1 ：不同位置的相同字符
              2 ：一个串不存在相同的字符
思路:统计每个小写字母的数量,考虑每个字母存在 取1个与不取 的情况，累乘即可
最后去除空的情况
*/
 
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 
const ll mod = 1e9+7;
const int maxn = 1e5+7;
ll sum[27];
 
int main (){
    int n;cin>>n;
    string s;cin>>s;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++) sum[s[i]-'a']++;
    ll ans=1;
    for(int i=0;i<=26;i++) ans=ans*(sum[i]+1)%mod;
    ans=(ans-1+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
 
 