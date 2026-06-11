#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    string t;
    cin >> s >> t;
    int len_s = (int)s.size();
    int len_t = (int)t.size();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    if(s < t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}