#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    map<int,int>dmp,tmp;
    vector<int>d(n);
    
    REP(i,n){
        cin >> d[i];
        dmp[d[i]]++;
    }
    int m;
    cin >> m;
    vector<int>t(m);
    REP(i,m){
        cin >> t[i];
        tmp[t[i]]++;
    }
    for(auto itr = tmp.begin(); itr != tmp.end(); ++itr) {
        if(dmp[itr->first] < itr->second){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}