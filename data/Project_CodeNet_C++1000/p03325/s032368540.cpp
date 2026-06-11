#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
    ll N;
    cin >> N;
    vector<ll> even;
    for (int i = 0; i < N; i++) {
      ll a = 0;
      cin >> a;
      if (a % 2 == 0) even.push_back(a);
    }

    ll cnt = 0;
    bool check = true;
    for (int i = 0; i < even.size(); i++){
        while(even[i]%2==0){
          even[i] /= 2;
          cnt++;
        }
    } 
    cout << cnt << endl;
    return 0;
}