#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 2019;


int main(){
    set<char> ST;
    string S; cin >> S;
    for(auto ch : S){
        ST.insert(ch);
    }
    if(ST.size() == 3) cout << "Yes" << endl;
    else cout << "No" << endl;


}
