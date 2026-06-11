#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

vector<string> vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    string S,T;
    cin >> S>>T;

    bool flag = true;
    bool flag1 = true;

    if(S.size()<T.size()){
        cout << "UNRESTORABLE" << endl;
    }
    else{
        REP(i,S.size()-T.size()+1){
            REP(j,T.size()){
                char S_tmp = S.at(i + j);
                char T_tmp = T.at(j);
                flag = true;

                if(S_tmp=='?'){

                }
                else if(S_tmp==T_tmp){

                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                string U = S;

                REP(j,T.size()){
                    U.at(i + j) = T.at(j);
                }
                REP(j,U.size()){
                    if (U.at(j) == '?')
                    {
                        U.at(j) = 'a';
                    }
                }

                vec.push_back(U);
            }
        }

        sort(vec.begin(), vec.end());

        if(vec.size()==0){
            cout << "UNRESTORABLE" << endl;
        }
        else{
            cout << vec.at(0) << endl;
        }
    }
}
