#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m, ans = 0, count = 0;
    string str;
    vector<string> s(100);
    vector<string> t(100);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s.at(i);
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> t.at(i);
    }
    for(int i = 0; i < n; ++i){
        str = s.at(i);
        count = 0;
        for(int j = 0; j < n; ++j){
            if(str == s.at(j))
                count++;
        }
        for(int j = 0;j < m; ++j){
            if(str == t.at(j))
                count--;
        }
        if(count > ans)
            ans = count;
    }
    cout << ans << endl;
}
