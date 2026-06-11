#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    cin >> N;
    int now = 1000000000;
    int count = 0;

    vector<int> data(N);

    rep(i, N)
    {
        cin >> data.at(i);
    }
    sort(data.begin(), data.end(), greater<int>());

    rep(i, N)
    {
        if(data.at(i) < now){
            now = data.at(i);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}