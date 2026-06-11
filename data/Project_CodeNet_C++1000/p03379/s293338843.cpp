#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<ll> tmp(N);

    for(ll i = 0; i < N; i++) cin >> v[i];
    tmp = v;
    sort(tmp.begin(), tmp.end());

    ll num1,num2;
    num2 = tmp[N/2];
    num1 = tmp[N/2 - 1];


    for(int i = 0; i < N; i++){
        if(num2 <= v[i]){
            cout << num1 << endl;
        }else{
            cout << num2 << endl;
        }
    }


}
