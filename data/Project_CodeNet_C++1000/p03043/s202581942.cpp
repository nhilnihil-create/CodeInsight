
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, k;
    cin >> n >> k;
    long double prob=0;

    for(int i=1; i<=n; i++){
        long double iprob = 1;
        //サイコロを振った時点でk以上である場合
        if(i >= k){
            prob += 1;
            continue;
        }
        //k以上になるには何回表が出る必要があるか数える
        int count=0;

        while(true){
            if(pow(2,count)*i >= k) break;
            count ++;
        }
        for(int j=0; j<count; j++){
            iprob /= 2;
        }
        prob += iprob;
    }
    prob /= n;

    cout << setprecision(12) << prob << endl;
}