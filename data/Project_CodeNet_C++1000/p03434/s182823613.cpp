#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    vector<int> vec(N);
    cin >> N;

    int A = 0;
    int B = 0;

    rep(i, N)
    {
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end(), greater<int>());

    rep(i, N)
    {
        if(i % 2 == 0){
            A += vec.at(i);
        }else{
            B += vec.at(i);
        }
    }

    cout << A - B << endl;
    return 0;
}