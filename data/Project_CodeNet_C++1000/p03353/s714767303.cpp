#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    string s; cin >> s;
    set<string> se;
    int k, len = s.size(); sc(k)
    for (int i = 1; i <= k; i++){
        for (int j = 0; j <= len-i; j++) se.insert(s.substr(j, i));
    }
    auto it = se.begin();
    for (int i = 0; i < k-1; i++) it++;
    cout << *it << endl;
    return 0;
}