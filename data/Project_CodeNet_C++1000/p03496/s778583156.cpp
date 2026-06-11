#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll mi = a[0];
    ll mi_index = 0;
    for(int i = 0; i < N; i++){
        if(a[i] < mi){
            mi = a[i];
            mi_index = i;
        }
    }
    ll ma = a[0];
    ll ma_index = 0;
    for(int i = 0; i < N; i++){
        if(a[i] > ma){
            ma = a[i];
            ma_index = i;
        }
    }
    
    cout << 2*N-2 << endl;
    if(abs(mi) > abs(ma)){
        for(int i = 0; i < N; i++){
            if(i != mi_index){
                cout << mi_index+1 << " " << i+1 << endl;
            }
        }
        for(int i = 0; i < N-1; i++){
            cout << N-i << " " << N-i-1 << endl;
        }
    }
    else{
        for(int i = 0; i < N; i++){
            if(i != ma_index){
                cout << ma_index+1 << " " << i+1 << endl;
            }
        }
        for(int i = 0; i < N-1; i++){
            cout << i+1 << " " << i+2 << endl;
        }
    }

    return 0;
}
