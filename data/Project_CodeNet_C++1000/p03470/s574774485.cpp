#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);

    rep(i,N){
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    int min = 0;
    int count = 0;
    rep(i, N){
        if (min < vec.at(i)){
            min = vec.at(i);
            count += 1;
        }
    }

    cout << count << endl;
}