#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


int main(){

    int Q;
    cin >> Q;
    while(Q--){
        ll A, B;
        cin >> A >> B;
        ll C = A * B;
        ll ub = 1000000001;
        ll lb = 0;
        while(ub - lb > 1){
            ll mid = (ub + lb) / 2;
            if(mid * mid <= C){
                lb = mid;
            }
            else{
                ub = mid;
            }
        }

        ll S = lb;

        if(A == B){
            cout << 2*S - 2 << endl;
        }
        else if(S * S == C){
            cout<< 2*S - 3 << endl;
        }
        else{
            if(C / S - (C % S == 0) == S){
                cout << 2 * S - 2 << endl;
            }
            else{
                cout << 2 * S - 1 << endl;
            }
        }
    }
    

    return 0;
}
