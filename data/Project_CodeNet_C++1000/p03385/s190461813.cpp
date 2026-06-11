#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string s;
    cin >> s;
    set<int> se;
    for(int i=0;i<s.size();i++){
        se.insert(s[i] -'a');
    }
    if(se.size()==3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}