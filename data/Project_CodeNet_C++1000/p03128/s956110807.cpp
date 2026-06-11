#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string mx = "";
void dfs(vector< pair<int,int> > &A, string s, int rest) {
    if(rest == 0) {
        if(s.size() > mx.size()) {
            mx = s;
        } else if(s.size() == mx.size()) {
            mx = max(mx, s);
        }
        return;
    } else if(rest < 0) {
        return;
    } else {
        for(auto a: A) {
            dfs(A, s+char('0' - a.second), rest-a.first);
        }
    }
}

int main(void) {
    vector<int> num = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    int N, M;
    cin >> N >> M;
    vector < pair<int,int> > A;
    for(int i=0; i<M; i++) {
        int a;
        cin >> a;
        A.emplace_back(num[a-1], -a);
    }

    sort(A.begin(), A.end());

    int p = N / A.front().first;
    p = max(p-6, 0);
    int rest = N - p * A.front().first;
    string ans(p, '0' - A.front().second);
    dfs(A, "", rest);

    ans += mx;
    sort(ans.rbegin(), ans.rend());
    cout << ans << endl;
    return 0;
}
