#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    string s,ans;
    cin >> s;
    int cnt = 0;
    rep(i,s.size()){
        if(i == 0){
            if(s[i] != 'A'){
                cout << "WA";
                exit(0);
                }
            }
        else if(isupper(s[i])){
            if(i == 1 || i == s.size()-1 || s[i] != 'C'){
                cout << "WA";
                exit(0);
            }
            cnt++;
        }
    }
    if(cnt != 1){cout << "WA";exit(0);}
    cout << "AC";
}