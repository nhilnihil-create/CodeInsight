#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string s;
    cin >> s;

    int year, month, day;
    year = stoi(s.substr(0, 4));
    month = stoi(s.substr(5, 2));
    day = stoi(s.substr(8, 2));
    if(year < 2019) cout << "Heisei" << endl;
    else if(year == 2019){
        if(month <= 4){
            cout << "Heisei" << endl;
        }
        else{
            cout << "TBD" << endl;
        }
    }
    else{
        cout << "TBD" << endl;
    }
    return 0;
}