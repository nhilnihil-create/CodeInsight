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
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

int main(){
    vector<char>A(4);
    for(int i = 0;i < 4;i++)
        cin >> A.at(i);
    
    vector<int>B(4);
    for(int i = 0;i < 4;i++)
        B.at(i) = A.at(i) - 48;

    vector<char>op(3);

    bool fla = false;

    for(int tmp=0;tmp < (1 << 3);tmp++){
        bitset<3>s(tmp);

        int sum =B.at(0);

        for(int i = 0;i < 3;i++){
            if(s.test(i)){
                sum += B.at(i+1);
                op.at(i) = '+';
            }else{
                sum -= B.at(i+1);
                op.at(i) = '-';
            }
        }

        if(sum == 7){
            fla = true;
            break;
        }

    }

    cout << B.at(0) << op.at(0) << B.at(1) << op.at(1) << B.at(2) << op.at(2) << B.at(3);
    cout << "=7" << endl;

}