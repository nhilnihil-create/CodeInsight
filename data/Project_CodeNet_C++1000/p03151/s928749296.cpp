#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vll A(N); vll B(N); 
    vll dif(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    for(int i=0; i<N; i++){
        dif[i] = A[i] - B[i];
    }
    sort(dif.begin(),dif.end());
    if(dif[0] >= 0){cout << 0;}
    else{
    ll sum = 0;
    for(auto x: dif){
        sum += x;
    }
    if(sum < 0){cout << -1;}
    else{int h = N-1;
    int k = 0;
    while(dif[k] < 0&&k != h){
        if(0-dif[k] < dif[h]){
            dif[h] += dif[k];
            dif[k] = 0;
            k++;
        }
        else if(0-dif[k] == dif[h]){
            dif[k] = 0;
            dif[h] = 0;
            h--; k++;
        }
        else{
            dif[k] += dif[h];
            dif[h] = 0;
            h--;
        }
    }
    if(k == h){
        if(dif[k] >= 0){
            cout << k+N-h;
        }
        else{
            cout << -1;
        }
    }
    else{
        cout << k+N-h;
    }
    }
    }
}
   