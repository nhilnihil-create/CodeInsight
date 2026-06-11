#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int N; 
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());
    cout << vec.back()-vec.at(0) << endl;
}