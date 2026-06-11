#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    string s,t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<int>());
    if(s>=t){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
