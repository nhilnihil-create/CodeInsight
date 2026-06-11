#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    string s;
    cin >> s;
    bool ans=true;
    if(s[0]!='A') ans=false;
    int cnt_C=0;
    for(int i=1;i<s.size();i++){
        if(s[i]<'a'){
            if(s[i]=='C'&&cnt_C==0&&1<i&&i<s.size()-1){
                cnt_C++;
                continue;
            }
            ans=false;
            break;
        }
    }
    if(cnt_C!=1) ans=false;
    puts(ans?"AC":"WA");
}