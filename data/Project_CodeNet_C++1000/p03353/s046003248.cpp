#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <string>
#include <ctime>
using namespace std;

string s; int K;
void input()
{
    cin >> s >> K;
}

void solve()
{
    int n = s.size();
    set<string> st;
    for (int i = 0; i < n; ++i){
        for (int j = 1; j <= min(K,n-i); ++j){
            // cout << s.substr(i,j) << endl;
            st.insert(s.substr(i,j));
        }
    }

    vector<string> vs;
    for (auto itr = st.begin(); itr != st.end(); ++itr){
        vs.emplace_back(*itr);
    }

    sort(vs.begin(),vs.end());

    cout << vs.at(K-1) << endl;
} 

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}