#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdlib>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    set<string> p;
    for (int i = 0; i < s.size(); i++){
        string t = "";
        for (int j = 0; j < s.size() - i && j < 6; j++){
            t += s[i + j];
            p.insert(t);
        }
    }
    rep(i, k - 1){
        p.erase(p.begin());
    }
    string ans = *p.begin();
    cout << ans << endl;
}