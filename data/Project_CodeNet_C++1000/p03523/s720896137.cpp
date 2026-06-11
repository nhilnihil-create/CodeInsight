#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K,typename V>
using umap = unordered_map<K,V>;
template <typename V>
using uset = unordered_set<V>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(v) v.begin(),v.end()

#define INF 1'000'000'000'000 //10^12
#define MOD 1'000'000'007

int main(){

    string input;
    cin >> input;
    int n = input.length();

    uset<string> strSet;

    string s[2] = {"","A"};

    for(int i=0;i<(1<<4);i++){
        strSet.insert(s[(i>>0)&1]+"KIH"+s[(i>>1)&1]+"B"+s[(i>>2)&1]+"R"+s[(i>>3)&1]);
    }


    if(strSet.find(input)!=strSet.end()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}
