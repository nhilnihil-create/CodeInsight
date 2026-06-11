#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    string s;
    cin >> s;
    for(char c:s){
        if(c == '1'){
            cout << '9';
        }else { 
            cout << '1';
        }
    }
}