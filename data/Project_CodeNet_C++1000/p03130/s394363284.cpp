#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int a;
    vector<ll>n(5);
    map<int,int>m;
    REP(i,5){
        n[i] = 0;
    }
    REP(i,6){
        cin >> a;
        n[a]++;
    }
    REP(i,5){
        m[n[i]]++;
    }
    if(m[1]==2 && m[2] == 2)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}