#include <bits/stdc++.h>
using namespace std;
int lcs(vector<vector<int>> &l, vector<vector<int>> &state, string &s, string &t, int m, int n){
    if(m < 0 || n < 0){
        return 0;
    }
    if(state[m][n] != -1){
        return l[m][n];
    }
    if(s[m] == t[n]){
        state[m][n] = 0;
        return l[m][n] = 1 + lcs(l, state, s, t, m-1, n-1);
    }
    else{
        if(lcs(l, state, s, t, m-1, n) > lcs(l, state, s, t, m, n-1)){
            state[m][n] = 1;
            return l[m][n] = lcs(l, state, s, t, m-1, n);
        }
        else{
            state[m][n] = 2;
            return l[m][n] = lcs(l, state, s, t, m, n-1);
        }
    }
}

string print(vector<vector<int>> &state, string &s, int i, int j){
    if(i < 0 || j < 0){
        return "";
    }
    if(state[i][j] == 0){
        string temp = print(state, s, i-1, j-1);
        temp.push_back(s[i]);
        return temp;
    }
    else if(state[i][j] == 1){
        return print(state, s, i-1, j);
    }
    return print(state, s, i, j-1);
}

int main(){
    string s, t;
    cin>>s>>t;
    vector<vector<int>> state(s.size(), vector<int> (t.size(), -1)), l(s.size(), vector<int> (t.size(), -1));
    int anslen = lcs(l, state, s, t, s.size() -1 , t.size() -1);
    cout<<print(state, s, s.size()-1, t.size()-1);
    return 0;
}
