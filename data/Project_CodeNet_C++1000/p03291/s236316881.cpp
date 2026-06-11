#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define bitrep(X,N) for(ll X = 0; X < (1 << (N)); X++)
#define PI (acos(-1.0))
#define sorta(V) sort(V.begin(), V.end())
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end() 


using namespace std;

int main(){

    string s;
    cin >> s;

    int size = s.size();

    vector<ll> a(100001);
    vector<ll> ab(100001);
    vector<ll> abc(100001);

    ll q = 1;

    for(int i = 1; i <= size; i++){
        if(s[i - 1] == 'A'){
            a[i] = (a[i - 1] + q) % MODN;
            ab[i] = ab[i - 1];
            abc[i] = abc[i - 1];

        }else if(s[i - 1] == 'B'){

            a[i] = a[i - 1];
            ab[i] = (ab[i - 1] + a[i - 1]) % MODN;
            abc[i] = abc[i - 1];

        }else if(s[i - 1] == 'C'){

            a[i] = a[i - 1];
            ab[i] = ab[i - 1];
            abc[i] = (abc[i - 1] + ab[i - 1]) % MODN;

        }else{
            
            a[i] = (3 * a[i - 1] + q) % MODN;
            ab[i] = (3 * ab[i - 1] + a[i - 1]) % MODN;
            abc[i] = (3 * abc[i - 1] + ab[i - 1]) % MODN;

            q = (q * 3) % MODN;
        }

        //cerr << a[i] << " " << ab[i] << " " << abc[i] << endl;
    }

    cout << abc[size] << endl;
    return 0;
}