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
    string s;
    cin >> s;
    string key = "keyence";
    REP(i,7){
        string a = s.substr(0,7-i);
        string b = s.substr(s.length()-i,i);
        if(a+b==key){
            cout << "YES" << endl;
            return 0; 
        }
    }
    cout << "NO" << endl;
    return 0;
}