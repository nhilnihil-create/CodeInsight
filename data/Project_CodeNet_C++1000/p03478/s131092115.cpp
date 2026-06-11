#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;
    for(int n=1; n<=N; n++){
        string str = to_string(n);
        int sum =0;
        for(int j=0; j<str.size(); j++){
            sum += str[j] - '0';
        }

        if(sum >= A && sum <= B){
            ans += n;
        }
    }
    cout << ans << endl;
    return 0;
}