#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
map<char, char> mp;
map<char, char> mp2;

int main(){
    string s,t;
    cin>>s>>t;
    ll n=s.length();
    bool f=true;
    for(char c='a';c<='z';c++){
        mp[c]='A';
        mp2[c]='A';
    }
    for(int i=0;i<n;i++){
        if(mp[s[i]]=='A'){
            mp[s[i]]=t[i];
        }else{
            if(mp[s[i]]!=t[i]){
                f=false;
                break;
            }
        }
        if(mp2[t[i]]=='A'){
            mp2[t[i]]=s[i];
        }else{
            if(mp2[t[i]]!=s[i]){
                f=false;
                break;
            }
        }
    }
    if(f){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
