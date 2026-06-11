#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string S;
    cin >> S;
    cout << (int)count(S.begin(), S.end(), '2') << endl;
    return 0;
}
