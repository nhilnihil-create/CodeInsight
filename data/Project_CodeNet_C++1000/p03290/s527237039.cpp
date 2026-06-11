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
    int d;
    ll g;
    cin >> d >> g;
    vector<ll>p(d),c(d);
    REP(i,d)cin >> p[i] >> c[i];
    ll answer = INT64_MAX;
    ll ope,tmpscore;
    for (int bit = 0; bit < (1<<d); ++bit) {
        ope=tmpscore=0;
        int max_pro=0;
        for (int i = 0; i < d; ++i) {
            if (bit & (1<<i)) {
                ope+=p[i];
                tmpscore+=p[i]*(i+1)*100+c[i];
            }else{
                max_pro = max(max_pro,i);
            }
        }
        int j = 0;
        while(tmpscore < g && j < p[max_pro]-1){
            tmpscore+=100*(max_pro+1);
            ope++;
            j++;
        }
        if(tmpscore >= g){
            answer = min(answer,ope);
        }
    }
    cout << answer << endl;
    return 0;
}