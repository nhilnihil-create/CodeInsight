#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int N = in();
    string before = "";
    int number = 0;
    cout << number << "\n";
    cout.flush();
    before = in<string>();
    bool plus = 1;
    for (int i = 19; i >= 0; i--){
        if(before == "Vacant")break;
        if(plus == 0 || number+(1<<i) < N){
            if(plus){
                number+=(1<<i);
            }else{
                number-=1<<i;
            }
            cout << number << "\n";
            cout.flush();
            string tmp = in<string>();
            if(tmp == before){
                plus = 1;
            }else if(tmp == "Vacant"){
                break;
            }else{
                plus = 0;
            }
        }
        cout.flush();
    }
}