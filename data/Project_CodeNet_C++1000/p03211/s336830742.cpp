#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> ans(s.size()-2);
    for (int i = 0; i < s.size()-2; i++){
        int n;
        string temp;
        temp = s.at(i);
        temp+= s.at(i+1);
        temp+= s.at(i+2);
        n = stoi(temp);
        ans.at(i) = abs(n - 753);
    }
    sort(ans.begin(), ans.end());//小さい順に並べる
    cout << ans.at(0) << endl;
}