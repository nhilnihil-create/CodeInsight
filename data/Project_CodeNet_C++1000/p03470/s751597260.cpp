#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i, N){
        cin >> vec.at(i);
    }

    int tmp;
    rep(i, N){
        for (int j = i + 1; j < N; j++)
        {
            if(vec.at(i) > vec.at(j)){
                tmp = vec.at(i);
                vec.at(i) = vec.at(j);
                vec.at(j) = tmp;
            }
        }
    }
    int current = 0;
    int count = 0;
    rep(i, N){
        if(current < vec.at(i)){
            current = vec.at(i);
            count += 1;
        }
    }
    cout << count << endl;
}