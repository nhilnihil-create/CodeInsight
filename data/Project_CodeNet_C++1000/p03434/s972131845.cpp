#include<bits/stdc++.h>
using namespace std; //std::の省略のため
using ll = long long;

int main(){
    int N;
    cin >> N;

    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    sort(a,a + N, greater<int>());

    int alice = 0, bob = 0;

    for(int i = 0; i < N; i++){
        if(i%2 == 0) alice += a[i];
        else bob += a[i];
    }

    int ans = alice - bob;
    cout << ans << endl;
}