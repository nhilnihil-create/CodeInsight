#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;


int main(){

    string S,T;
    cin >> S >> T;

    map<char,int> mp_s;
    map<char,int> mp_t;


    rep(i,S.size()) mp_s[S[i]]++;
    rep(i,T.size()) mp_t[T[i]]++;
    vector<ll> char_s;
    vector<ll> char_t;
    rep(i,26){
        if(mp_s['a' + i] != 0)  char_s.push_back(mp_s['a' + i]);
    } 
    rep(i,26){
        if(mp_t['a' + i] != 0)  char_t.push_back(mp_t['a' + i]);
    } 
    sort(all(char_s));
    sort(all(char_t));
    rep(i,char_s.size()){
        if(char_s[i] != char_t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}