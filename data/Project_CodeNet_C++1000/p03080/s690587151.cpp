#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    if ((int)count(s.begin(), s.end(), 'R')*2 > N) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
