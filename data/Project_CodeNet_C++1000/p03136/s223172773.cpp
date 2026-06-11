#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)


int main(){
    int N;
    vector<int> Ls;

    cin >> N;

    Ls.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Ls[i];
    }

    cout << (*max_element(Ls.begin(), Ls.end()) * 2 < accumulate(Ls.begin(), Ls.end(), 0) ? "Yes" : "No") << endl;

    return 0;
}