#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


int n;
string s, t;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>s>>t;
    n = s.size();
    vector<vector<int>> ms(26), mt(26);
    for (int i=0; i<n; i++) {
	ms[s[i]-'a'].push_back(i);
	mt[t[i]-'a'].push_back(i);
    }

    // Each char will be of form:
    // 1. A->X
    // 2. B->Y and Y->B (cycle)

    // AABYAY
    // XXYBXB

    sort(ms.begin(),ms.end());
    sort(mt.begin(),mt.end());

    cout<<(ms==mt ? "Yes\n" : "No\n");
    
    return 0;
}
