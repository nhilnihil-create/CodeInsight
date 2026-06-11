#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

string yes = "Yes";
string no = "No";

int T;
ll A, B, C, D;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){


    cin >> T;
    for(int ite = 0; ite < T; ite++){
        cin >> A >> B >> C >> D;
        if(A < B){
            cout << no << endl;
        }
        else if(D < B){
            cout << no << endl;
        }
        else if(B - 1 <= C){
            cout << yes << endl;
        }
        else{
            ll d = D % B;
            ll g = gcd(d, B);
            ll a = A % B;
            if(a > C){
                cout << no << endl;
            }
            else{
                // a + g * n > C
                ll n = (C - a) / g + 1;
                if(a + g * n < B){
                    cout << no << endl;
                }
                else{
                    cout << yes << endl;
                }
            }
        }
    }

    return 0;
}
