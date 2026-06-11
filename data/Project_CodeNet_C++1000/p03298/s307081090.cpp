#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;


int main(int argc, char const *argv[]) {
    int n;cin>>n;
    string s;cin>>s;
    map<pair<string,string>,int> ma;
    for(int i=0;i<(1<<n);++i){
        int b=i;
        string k="",l="";
        for(int j=0;j<n;++j){
            if((i>>j)%2==0)k = k+s[j];
            else l = l+s[j];
        }
        ma[pair<string,string>(k,l)]++;
    }
    long long res=0;
    for(int i=0;i<(1<<n);++i){
        int b=i;
        string k="",l="";
        for(int j=0;j<n;++j){
            if((i>>j)%2==0)k = k+s[2*n-1-j];
            else l = l+s[2*n-1-j];
        }
        res+=ma[pair<string,string>(k,l)];
    }
    cout<<res<<endl;
    return 0;
}