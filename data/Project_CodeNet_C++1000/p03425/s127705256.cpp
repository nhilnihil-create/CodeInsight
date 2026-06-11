#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N; map<char,long long> M;
void input()
{
    cin >> N;
    for (int i = 0; i < N; ++i){
        string s; cin >> s;
        M[s[0]]++;
    }
}

void solve()
{
    vector<char> head = {'M','A','R','C','H'};
    long long ans = 0;
    for (int i = 0; i < head.size()-2; ++i){
        for (int j = i+1; j < head.size()-1; ++j){
            for (int k = j+1; k < head.size(); ++k){
                // cout << head[i] << " " << head[j] << " " <<  head[k] << endl;
                ans += M[head[i]] * M[head[j]] * M[head[k]];
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}