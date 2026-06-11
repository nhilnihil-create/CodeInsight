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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
string s;
string t;

bool judge(int i){
    for(int j=0;j<t.length();j++){
        if(s[i+j]!=t[j] && s[i+j]!='?') return false;
    }
    return true;
}

int main(){
    cin>>s>>t;
    bool f=true;
    for(int i=s.length()-t.length();i>=0;i--){
        if(judge(i)){
            f=false;
            for(int j=0;j<t.length();j++){
                s[i+j]=t[j];
            }
            break;
        }
    }
    if(f){
        cout<<"UNRESTORABLE"<<endl;
    }else{
        for(int i=0;i<s.length();i++){
            if(s[i]=='?') s[i]='a';
        }
        cout<<s<<endl;
    }
}