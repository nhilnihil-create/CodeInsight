#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;


int main() {
    int N; 
    cin >> N;
    vector<int> vec(N);
    int sum=0;
    int m=0;
    for(int i=0; i<N; i++){
        cin >> vec.at(i);
        sum += vec.at(i);
        m = max(m,vec.at(i));
    }
    cout << sum - m/2 << endl;
}