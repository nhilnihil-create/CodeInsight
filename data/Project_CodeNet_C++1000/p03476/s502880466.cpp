#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int Q;
    cin >> Q;
    vector<int> l(Q);
    vector<int> r(Q);
    rep(i,Q){
        cin >> l[i] >> r[i];
    }
    vector<bool> isPrime(100005,true);
    isPrime[1] = false;
    for (int i = 2; i <= 100000; i++){
        if (isPrime[i]){
            for (int j = 2; j * i <= 100000; j++){
                isPrime[i * j] = false;
            }
        }
    }
    vector<int> like2017(100005, 0);
    for (int i = 3; i <= 99999; i += 2){
        if (isPrime[i] && isPrime[(i + 1) / 2]){
            like2017[i]++;
        }
    }
    for (int i = 1; i <= 100000; i++){
        like2017[i + 1] += like2017[i];
    }
    rep(i,Q){
        cout << like2017[r[i]] - like2017[l[i] - 1] << endl;
    }
}