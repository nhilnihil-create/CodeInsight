#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>

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
    vector<int> a(3),b(3);

    vector<int> mati(4);

    int dcount=0;

    for(int i = 0;i < 3;i++){
        cin >> a.at(i) >> b.at(i);
    }

    for(int i = 0;i < 4;i++){
        mati.at(i) = 0;
    }

    for(int i = 0;i < 3;i++){
        mati.at(a.at(i) -1)++;
        mati.at(b.at(i) -1)++;
    }

    for(int i = 0;i < 4;i++){
        if(mati.at(i) == 2){
            dcount++;
        }
    }

    if(dcount == 2)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
    

}