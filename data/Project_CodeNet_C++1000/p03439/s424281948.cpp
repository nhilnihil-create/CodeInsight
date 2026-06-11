#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    string s;
    cout << 0 << endl;
    cin >> s;
    if (s == "Vacant") return 0;
    bool check = (s == "Male");
    cout << N-1 << endl;
    cin >> s;
    if (s == "Vacant") return 0;
    int l = 0;
    int r = N;
    while (r-l > 1) {
        int c = (l+r)/2;
        cout << c << endl;
        cin >> s;
        if ((s == "Male") ^ (!check) ^ (c%2==0)) r = c;
        else l = c;
    }
    cout << r << endl;
    cin >> s;
    return 0;
}
