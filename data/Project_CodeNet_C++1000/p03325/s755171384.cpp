#include<bits/stdc++.h>
using namespace std;

int func(int a){
    int sum = 0;
    while(a % 2 == 0){
        sum++;
        a /= 2;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += func(A.at(i));
    }
    cout << ans << endl;
    return 0;
}