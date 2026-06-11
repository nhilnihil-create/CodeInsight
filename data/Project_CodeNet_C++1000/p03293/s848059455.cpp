#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    bool judge = false;
    for(int i = 0;i < s.size();i++){
        if(s == t)judge = true;
        string memo = s;
        s = memo.at(memo.size() - 1);
        memo.pop_back();
        s += memo;
    }
    if(judge)cout << "Yes" << endl;
    else cout << "No" << endl;
}