#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n;
    cin >> n;
    set<string>c;
    string s="";
    rep(i, 0, n) {
        string in;
        cin >> in;
        if(c.count(in) || (s!="" && s.back()!=in[0])){
            cout << "No" << endl;
            return 0;
        }
        c.insert(in);
        s=in;
    }
    cout << "Yes" << endl;
    return 0;
}
