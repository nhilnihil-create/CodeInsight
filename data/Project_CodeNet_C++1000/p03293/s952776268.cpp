#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e9 
typedef long long ll;
typedef long double ld;
int main(){
    string s,t;
    cin>>s>>t;
    queue<char> p,q;
    REP(i,SIZE(s)){
        char c=s[i];
        char d=t[i];
        p.push(c);
        q.push(d);
    }
    bool is=false;
    REP(i,SIZE(s)){
        char f=p.front();
        p.pop();
        p.push(f);
        if(p==q){
            is=true;
            break;
        }
    }
    cout<<(is?"Yes":"No")<<endl;
    return 0;
}
