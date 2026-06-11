#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    while(b > 0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

ll lcm(ll a, ll b){
    return (a/(gcd(a, b)))*b;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        if(A < B || D < B){
            cout << "No" << endl;
        }else if(C >= B-1){
            cout << "Yes" << endl;
        }
        else{
            ll m = gcd(B, D);
            if(B-1-C >= m){
                cout << "No" << endl;                
            }else if(((C+1)%m) <= (A%m) && (A%m) <= ((B-1)%m)){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }
    }
}