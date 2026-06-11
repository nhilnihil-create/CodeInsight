#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
ll N;

int dfs(string s){
    ll ret = 0;
    vector<char> lis = {'3','5','7'};
    if((int)s.size() > 0){
        if(stoll(s) > N){
            return ret;
        }else{
            bool ok = true;
            for(auto x:lis){
                if(s.find(x) == string::npos) ok = false;
            }
            if(ok) ret++;
        }
    }
    for(auto c:lis){
        s.push_back(c);
        ret += dfs(s);
        s.pop_back();
    }
    return ret;

}

int main(){
    cin >> N;
    string S = "";
    cout << dfs(S) << endl;
}