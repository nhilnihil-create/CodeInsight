#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    set<string> substr;
    string s;
    int K;
    cin >> s >> K;

    for(int begin=0; begin<s.size(); begin++) {
        for(int end = 1; end<=K; end++) {
            string t = s.substr(begin, end);
            substr.insert(t);
        }
    }
  auto itr = substr.begin();
  advance(itr, K-1);
  cout << *itr << endl;
}

