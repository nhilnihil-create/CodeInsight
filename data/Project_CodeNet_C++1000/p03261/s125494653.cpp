#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//using ll = long long;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i,n)cin >> w[i];
    char e;//endword
    rep(i,n){
        string s = w[i];
        if(i == 0)e = s[s.size()-1];
        else{
            if(e != s[0]){
                cout << "No" << endl;
                exit(0);
            }
            else e = s[s.size()-1];
        }
       // cout << e;
    }
    sort(w.begin(),w.end());
    rep(i,n-1){
        if(w[i] == w[i+1]){
            cout << "No" << endl;
            exit(0);
            }
    }
    cout << "Yes" << endl;
}