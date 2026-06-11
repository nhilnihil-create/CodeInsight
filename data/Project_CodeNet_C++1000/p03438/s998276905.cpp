#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for(auto &a:A){
        cin >> a;
    }
    for(auto &b:B){
        cin >> b;
    }

    ll suma,sumb;
    suma=sumb=0;
    for(int i=0; i<N; i++){
        ll a=A[i];
        ll b=B[i];
        if(a>b){
            sumb+=(a-b);
        }else{
            suma+=(b-a)/2+(b-a)%2;
            sumb+=(b-a)%2;
        }
    }
    //cout << suma << ' ' << sumb << endl;
    if(suma<sumb){
        cout << "No\n";
        return 0;
    }else{
        cout << "Yes\n";
        return 0;
    }
}