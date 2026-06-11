#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

int main(){
    string s; cin>>s;
    int a = 10*(s[0]-'0')+(s[1]-'0');
    int b = 10*(s[2]-'0')+(s[3]-'0');
    if (0<a&&a<=12 && 0<b&&b<=12){
        cout<<"AMBIGUOUS"<<endl;
    }else if(!(0<a&&a<=12) && !(0<b&&b<=12)){
        cout<<"NA"<<endl;
    }else if(0<a&&a<=12){
        cout<<"MMYY"<<endl;
    }else if(0<b&&b<=12){
        cout<<"YYMM"<<endl;
    }
}