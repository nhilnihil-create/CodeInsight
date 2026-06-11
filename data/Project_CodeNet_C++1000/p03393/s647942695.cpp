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
    string S = in<string>();
    if(S == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << "\n";
    }else if(S.size() == 26){
        string before = S;
        next_permutation(ALL(S));
        int stop = 0;
        REP(i,26){
            if(S[i] != before[i]){
                stop = i;
                break;
            }
        }
        cout <<S.substr(0,stop+1)<< "\n";
    }else{
        vector<bool> AS(26);
        REP(i,S.size()){
            AS[S[i] - 'a'] = 1;
        }
        REP(i,26){
            if(AS[i] == 0){
                char plus = i + 'a';
                S += plus;
                break;
            }
        }
        cout << S << "\n";
    }
}