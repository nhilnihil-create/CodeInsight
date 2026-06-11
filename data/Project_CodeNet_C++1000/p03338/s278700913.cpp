#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))


int main(){
    int N;
    string s;
    cin >> N >> s;

    string X,Y;
    int cnt,saidai=-1;
    for(int i = 1;i < N;i++){
        cnt = 0;
        X = s.substr(0,i);
        Y = s.substr(i,N-1);

        set<char>Xs,Ys;

        for(int j = 0;j < X.size();++j)
            Xs.insert(X.at(j));
        for(int j = 0;j < Y.size();++j)
            Ys.insert(Y.at(j));
        
        for(auto c:Xs){
            cnt += Ys.count(c);
        }
        
        if(cnt > saidai)
            saidai = cnt;
    }

    cout << saidai << endl;
}