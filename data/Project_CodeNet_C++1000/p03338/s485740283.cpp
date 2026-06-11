#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <sstream>
#include <bitset>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef long long ll;

using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(n-1,0);

    FOR(i, 1, n){
        string l = s.substr(0,i);
        string r = s.substr(i,n-i);
        for(char c='a';c<='z';c++){
            if ((l.find(c) != string::npos)&&(r.find(c) != string::npos)) {
                cnt[i-1]++;
            }
        }
    }

    int max = *max_element(cnt.begin(),cnt.end());

    cout << max << endl;

    return 0;
}
