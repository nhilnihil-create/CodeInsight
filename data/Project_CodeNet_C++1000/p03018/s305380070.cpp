#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;


int main(){
    string S, S_; cin >> S; S_ = S + 'p';
    int N = S.size();
    string X = "";
    for(int i = 0; i < N; i++){
        if(S_[i] == 'A') X += 'A';
        else if(S_[i] == 'B'){
            if(S_[i+1] == 'C') {X += 'D'; i++;}
            else X += 'B';
        }
        else X += 'C';
    }
    vector<ll> V(X.size()+5);
    for(int i = 0; i < X.size(); i++){
        if(i == 0){
            if(X[i] == 'A') V[i] = 1;
            else V[i] = 0;
        }
        else{
            if(X[i] == 'A') V[i] = V[i-1]+1;
            else if(X[i] == 'D') V[i] = V[i-1];
            else if(X[i] == 'B' || X[i] == 'C') V[i] = 0;
        }
    }
    ll cnt = 0;
    for(int i = 0; i < X.size(); i++){
        if(X[i] == 'D'){
            cnt += V[i];
        }
    }
    cout << cnt << endl;
}