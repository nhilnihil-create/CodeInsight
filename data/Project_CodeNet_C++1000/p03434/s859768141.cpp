#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int alice = 0;
    int bob = 0;

    sort(a, a + N, greater<int>());
    bool count = true;
    for (int i = 0; i < N; i++) {
        if (count == true){
            alice += a[i];
            count = false;
        }else{
            bob += a[i];
            count = true;
        }
    }

    cout << alice - bob << endl;
}