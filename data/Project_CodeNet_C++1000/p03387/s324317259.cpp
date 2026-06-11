#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    priority_queue<int, vector<int>, greater<int>> que;
    que.push(A);que.push(B);que.push(C);

    int count = 0;
    while(true){
        int min_val = que.top(); que.pop();
        int medium_val = que.top(); que.pop();
        int max_val = que.top(); que.pop();

        if(min_val==medium_val && medium_val==max_val){
            break;
        }

        if(min_val == medium_val){
            count += 1;
            que.push(max_val);
            que.push(medium_val+1);
            que.push(min_val+1);
        }else{
            count += 1;
            que.push(max_val);
            que.push(medium_val);
            que.push(min_val+2);
        }

    }

    cout << count << endl;
    return 0;
}