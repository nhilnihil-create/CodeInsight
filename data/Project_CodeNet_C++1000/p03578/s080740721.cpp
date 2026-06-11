#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    int m;
    cin >> m;
    vector<int> t(m);
    for(int i = 0; i < m; i++) cin >> t[i];

    map<int, int> problems;
    for(int i = 0; i < n; i++){
        if(problems.count(d[i])) problems[d[i]]++;
        else problems[d[i]] = 1;
    }

    string ans = "YES";
    for(int i = 0; i < m; i++){
        if(problems.count(t[i])){
            if(problems[t[i]] == 1) problems.erase(t[i]);
            else problems[t[i]]--;
        }else{
            ans = "NO";
        }
    }
    cout << ans << endl;
    return 0;
}