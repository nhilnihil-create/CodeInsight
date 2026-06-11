#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;


int main(){
    ll N; cin >> N;
    string S; cin >> S;
    vll black(N);
    vll white(N);
    ll b = 0; ll w = 0;
    for(int i=0; i<N; i++){
        if(S[i] == '#'){
            b++;
        }
        black[i] = b;
    }
    for(int i=0; i<N; i++){
        if(S[N-1-i] == '.'){
            w++;
        }
        white[N-1-i] = w;
    }
    ll mini = N;
    for(int i=0; i<N; i++){
        ll j;
        if(S[i] == '#'){
            j = black[i] + white[i];
        }
        else{
            j = black[i] + white[i] - 1;
        }
        if(mini > j){mini = j;}
    }
    ll h = min(N-b,N-w);
    cout << min(h,mini);
}