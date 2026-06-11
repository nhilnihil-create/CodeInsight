#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    int a; cin >> a;
    string s; cin >> s;
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        string a = s.substr(0,i);
        string b = s.substr(i);
        set<char> ast; for(char c:a) ast.insert(c);
        set<char> bst; for(char c:b) bst.insert(c);
        int cnt = 0;
        for(auto it = ast.begin(); it != ast.end(); ++it){
            if(bst.find(*it) != bst.end()){
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}