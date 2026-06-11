#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    string s;
    int K;
    cin >> s >> K;
    set<string> t;
    for (int i = 0; i < s.size(); i++) for (int j = 1; j <= K; j++) t.insert(s.substr(i, j));
    auto itr = t.begin();
    for (int i = 0; i < K - 1; i++) itr++;
    cout << *itr << endl;
}
