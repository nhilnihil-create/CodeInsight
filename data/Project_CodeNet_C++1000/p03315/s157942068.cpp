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

ll M = 1000000007;

int main(){
    string S; cin >> S;
    ll a=0;
    for(int i=0; i<4; i++){
        if(S[i]=='+'){
            a++;
        }else{
            a--;
        }
    }
    cout << a;
}