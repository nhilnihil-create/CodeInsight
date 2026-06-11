#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    string s,t;cin>>s>>t;
    vector<char> v1,v2;
    REP(i,SIZE(s))v1.push_back(s[i]);
    REP(i,SIZE(t))v2.push_back(t[i]);
    sort(ALL(v1));
    sort(v2.begin(), v2.end(), greater<>());
    string s1,t1;
    REP(i,SIZE(v1))s1+=v1[i];
    REP(i,SIZE(v2))t1+=v2[i];
    if(s1<t1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
