#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int n;
    cin >> n;
    long int ans;
    for (long int i = 0; i * i <= n; i++){
        ans = i * i;
    }
    cout << ans << endl;
}