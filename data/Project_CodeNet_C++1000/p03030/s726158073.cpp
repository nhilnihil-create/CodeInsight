#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n;
    vector<pair<string, pair<int, int>>> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int a;
        cin >> s >> a;
        v.push_back({s, {-a, i + 1}});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        cout << v[i].second.second << endl;
    return 0;
}
