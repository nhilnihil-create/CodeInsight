#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> P(N);
    for(int i=0; i<N; i++) {
        int x; cin >> x; x--;
        P[x] = i; 
    }
    int len = 0;
    int right = 0;
    for(int left = 0; left < N; left++) {
        while(right+1 < N && P[right] < P[right+1]) right ++;
        len = max(len, right-left+1);
        if(left==right) right ++;
    }
    cout << N - len << endl;
}