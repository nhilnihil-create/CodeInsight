#include <bits/stdc++.h>
using namespace std;

int div(int a){
    int count = 0;
    while (a%2 == 0){
        a /= 2;
        count++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i<n; i++){
        int a;
        cin >> a;
        ans += div(a);
    }
    cout << ans << endl;
}