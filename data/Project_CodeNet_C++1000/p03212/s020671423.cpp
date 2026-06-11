#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> c = {'3', '5', '7'};
long long N;
long long ans;
void dfs(string s){
    if(!s.empty() && atoll(s.c_str()) > N) return;
    int flag = 0;
    for(int i = 0; i < 3; i++){
        if(s.find(c[i]) == string::npos) flag = 1;
    }
    if(flag == 0) {
        ans++;
    }
    for(int i = 0; i < 3; i++){
        dfs(s + c[i]);
    }
}
int main(){
    cin >> N;
    ans = 0;
    string s;
    ans = 0;
    dfs(s);
    cout << ans << endl;
}