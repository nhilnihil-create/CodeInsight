#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x)
#define printl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;

int main(){
    ll A, B, C, K; cin >> A >> B >> C >> K;
    if(K%2 == 0){
        if(abs(A - B) > pow(10,18)){
            print("unfair");
        }else{
            print(A - B);
        }
    }else{
        if(abs(B - A) > pow(10,18)){
            print("unfair");
        }else{
            print(B - A);
        }
    }
}