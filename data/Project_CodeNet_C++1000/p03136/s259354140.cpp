#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int L[N];
    for(int i = 0 ; i < N ; i++){
        cin >> L[i];
    }
    sort(L,L+N,greater<int>());
    int sum = 0;
    for(int i = 1 ; i < N ; i++){
        sum += L[i];
    }
    if(L[0] < sum) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}