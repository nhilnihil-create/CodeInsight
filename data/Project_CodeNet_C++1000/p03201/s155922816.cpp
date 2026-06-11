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

ll INF = 100000000000;

int main(){ 
    ll N; cin >> N;
    vector<long double> A(N);
    vb(N, false);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vll B(0);
    for(int i=0; i<33; i++){
        B.emplace_back(pow(2,i));
    }
    ll count = 0;
    for(int i=N-1; i>=0; i--){
        long double k;
        for(auto x: B){
            if(x>A[i]){
                k = x;
                break;
            }
        }
        long double p = k - A[i];
        if(upper_bound(A.begin(), A.end()-(N-i), p)-lower_bound(A.begin(), A.end()-(N-i), p)>0){
            *(upper_bound(A.begin(), A.end()-(N-i), p)-1) += 0.1;
            A[i] += 0.1;
            count++;
        }
    }
    cout << count << endl;
}