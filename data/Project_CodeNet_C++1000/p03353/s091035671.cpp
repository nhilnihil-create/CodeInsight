#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    string s; cin >> s;
    int k; cin >> k;
    set<string> t;
    for(int i = 0; i < s.size(); i++){
            string h = "";
            h += s[i];
            t.insert(h);
        for(int j = i+1; j < min(i+k, (int)s.size()); j++){
            h += s[j];
            t.insert(h);
        }
    }
    auto itr = t.begin();
    for(int i = 1; i < k; i++) itr++;
    cout << *itr << endl;
    system("pause");
}