#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, count;
    cin >> N;
    count = 0;
    vector<int> vec(N);
    for (int i = 0; i < N; i++){
        cin >> vec.at(i);
    }
    for (int i = 0; i < N - 1; i++){
        vec.at(i + 1) = __gcd(vec.at(i), vec.at(i + 1));
    }
    while(vec.at(N - 1) % 2 == 0){
        count++;
        vec.at(N - 1) = vec.at(N - 1) * 0.5;
    }
    cout << count << endl;
}