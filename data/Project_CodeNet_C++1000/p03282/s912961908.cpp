#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    string s;
    unsigned long long k;
    cin >> s >> k;
    unsigned long long cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') cnt++;
        else{
            if(k<=cnt){
                cout << 1 << endl;
                return 0;
            }
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}