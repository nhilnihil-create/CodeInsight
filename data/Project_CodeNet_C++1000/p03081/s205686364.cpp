#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool f(const string& S, const vector<pair<char, int> >& td, int index){
    if(index == -1){
        return true;
    }
    if(index >= S.size()){
        return false;
    }
    for(const auto&a: td){
        char t,d; tie(t,d) = a;
        if(t == S[index]){
            index += d;
            if(index < 0){
                return true;
            }
            if(index >= S.size()){
                return false;
            }
        }
    }
    return false;
}

int solve(string S, vector<pair<char, int> > td){
    int ok = -1;
    int ng = S.size();
    while(abs(ok-ng) > 1){
        int mid = (ok+ng)/2;
        if(f(S, td, mid)) {
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    return ok+1;
}

int main(void){
    int N,Q; cin >> N >> Q;
    string S; cin >> S;
    vector<pair<char, int> > td(Q);
    for(auto &a:td){
        char t; char d; cin >> t >> d;
        a.first = t;
        a.second = (d == 'L' ? -1 : 1);
    }
    int left = solve(S, td);
    reverse(S.begin(), S.end());
    for(auto &a:td){
        a.second *= -1;
    }
    int right = solve(S, td);
    cout << max((int(S.size()) - left - right), 0) << endl;
    return 0;
}