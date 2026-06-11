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
    ll H, W, N; cin >> H >> W >> N;
    ll r,c; cin >> r >> c;
    string S, T; cin >> S >> T;
    bool t = true;
    ll p, q; p = r; q = c;
    for(int i=0; i<N; i++){
        if(S[i] == 'L'){
            c--;
        }else if(S[i] == 'U'){
            r--;
        }
        if(c<1||r<1){
            t = false;
            cout << "NO";
            break;
        }
        if(T[i] == 'R'&&W-c>1){
            c++;
        }else if(T[i] == 'D'&&r<H){
            r++;
        }
    }
    if(t){
        r = p; c = q;
    for(int i=0; i<N; i++){
        if(S[i] == 'L'){
            c--;
        }else if(S[i] == 'D'){
            r++;
        }
        if(c<1||r>H){
            t = false;
            cout << "NO";
            break;
        }
        if(T[i] == 'R'&&W-c>1){
            c++;
        }else if(T[i] == 'U'&&r>1){
            r--;
        }
    }
    }
    if(t){
        r = p; c = q;
    for(int i=0; i<N; i++){
        if(S[i] == 'R'){
            c++;
        }else if(S[i] == 'D'){
            r++;
        }
        if(c>W||r>H){
            t = false;
            cout << "NO";
            break;
        }
        if(T[i] == 'L'&&c>1){
            c--;
        }else if(T[i] == 'U'&&r>1){
            r--;
        }
    }
    }
    if(t){
        r = p; c = q;
    for(int i=0; i<N; i++){
        if(S[i] == 'R'){
            c++;
        }else if(S[i] == 'U'){
            r--;
        }
        if(c>W||r<1){
            t = false;
            cout << "NO";
            break;
        }
        if(T[i] == 'L'&&c>1){
            c--;
        }else if(T[i] == 'D'&&r<H){
            r++;
        }
    }
    }
    if(t){
        cout << "YES";
    }
}