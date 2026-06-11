#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    priority_queue<int> que;
    int val;

    for(int i=0; i<N; i++){
        cin >> val;
        que.push(val);
    }

    int ans = 0;
    bool isAlice = true;
    while (que.size() > 0){
        int tmp_val = que.top();que.pop();
        if (isAlice){
            ans += tmp_val;
        }else{
            ans -= tmp_val;
        }
        isAlice = !isAlice;
    }

    cout << ans << endl;
    return 0;

}