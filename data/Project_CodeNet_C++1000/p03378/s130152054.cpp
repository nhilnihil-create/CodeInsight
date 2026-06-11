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

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    int N,M,X,min = 10000,rs=0,t = 0;
    cin >> N >> M >> X;
    vector<int> A(M);

    for(int i = 0;i < M;i++)
        cin >> A.at(i);

    for(int i = 0;;i++){
        if(A.at(i) < X)
            rs++;
        else
        {
            t = i;
            break;
        }       
    }

    if(min > rs)
        min = rs;
    rs = 0;

    for(int i = t;i < A.size();i++){
        if(A.at(i) < N)
            rs++;
    }

    if(min > rs){
        min = rs;
    }

    cout << min << endl;

    

}