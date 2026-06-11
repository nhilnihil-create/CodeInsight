#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
vector<vector<int>> t;
vector<vector<int>> p;
vector<string> ans;
string id(int p, int num){
    string tmp1 = to_string(p);
    string tmp2 = to_string(num);
    while(tmp1.size()<6)tmp1='0'+tmp1;
    while(tmp2.size()<6)tmp2='0'+tmp2;
    return tmp1+tmp2;
}
int main() {
    cin >> N >> M;
    t.resize(M);
    p.resize(N);
    ans.resize(M);
    for (int i = 0; i < M; i++)
    {
        t[i].resize(3);
        cin >> t[i][1] >> t[i][0];
        t[i][2] = i;
    }
    sort(t.begin(), t.end());
    for(auto m : t){
        p[m[1]-1].push_back(m[2]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < p[i].size(); j++)
        {
            ans[p[i][j]]=id(i+1, j+1);
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        cout << ans[i] << endl;
    }
    

}