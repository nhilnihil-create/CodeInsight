#include <bits/stdc++.h>  
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define REP(i, a, op1, n, op2) for(int i=a; i op1 (int)(n); op2 ## op2 i)
#define cout(val) cout << (val) << endl

using namespace std;  

int main(){
    int d, g, sum, count, min=1001;
    cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    rep(i, d){
        cin >> p[i] >> c[i];
    }

    rep(i, 1<<d){
        sum = 0;
        count = 0;
        rep(j, d){
            if(i&1<<j){
                sum += 100 * (j+1) * p[j] + c[j];
                count += p[j];
            }
        }
        if(sum < g){
            for(int j=d-1; j>=0; j--){
                if(sum >= g) break;
                if(i&1<<j) continue;
                rep(k, p[j]){
                    sum += 100 * (j+1);
                    count++;
                    if(k-1 == p[j]) sum += c[j];
                    if(sum >= g) break;
                }
            }
        }
        if(min > count){
            min = count;
        }
    }
    cout(min);
}
