#include <iostream>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

void solve(std::string S){
    string s1 = S.substr(0, 2);
    string s2 = S.substr(2);
    int n1 = stoi(s1);
    int n2 = stoi(s2);
    if (n1 == 0) {
        if (n2 >= 1 && n2 <= 12) cout << "YYMM" << '\n';
        else cout << "NA" << '\n';
    }
    else if (n1 > 12) {
        if (n2 >= 1 && n2 <= 12) cout << "YYMM" << '\n';
        else cout << "NA" << '\n';
    } else {
        if (n2 >= 1 && n2 <= 12) cout << "AMBIGUOUS" << '\n';
        else cout << "MMYY" << '\n';
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
