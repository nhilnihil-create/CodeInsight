#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> vec(N);
    int S=0;
    int m=100000;
    for(int i=0; i<N; i++){
        cin >> vec[i];
        m = min(m, vec[i]);
        S += vec[i];
    }

    int count=N;
    while(S+m <= X){
        S += m;
        count++;
    }

    cout << count << endl;

}
