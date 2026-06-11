#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
   string s;cin >>s;
   int a=s[0]-'0';
   int b=s[1]-'0';
   int c=s[2]-'0';
   int d=s[3]-'0';
   vector<int>ans;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                int now=a;
                if(i)now+=b;
                else now-=b;
                if(j)now+=c;
                else now-=c;
                if(k)now+=d;
                else now-=d;
                if(now==7){
                    ans.push_back(i);
                    ans.push_back(j);
                    ans.push_back(k);
                }
            }
        }
    }
    cout <<a;
    if(ans[0])cout <<'+';
    else cout <<'-';
    cout <<b;
    if(ans[1])cout <<'+';
    else cout <<'-';
    cout <<c;
    if(ans[2])cout <<'+';
    else cout <<'-';
    cout <<d<<"=7"<<endl;
}
