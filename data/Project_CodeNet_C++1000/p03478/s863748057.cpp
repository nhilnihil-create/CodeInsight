#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1;i < n + 1;i++){
        int memo = 0;
        int j = i;
        while(true){
            memo += j % 10;
            j /= 10;
            if(j == 0)break;
        }
        if(a <= memo && memo <= b)ans += i;
    }
    cout << ans << endl;
}