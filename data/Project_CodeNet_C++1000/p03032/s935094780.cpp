#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
vector<int> V(55);
priority_queue<int, vector<int>, greater<int>> pq;  //val's queue
int res = 0;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> V[i];

    for(int i = 0; i <= min(N, K); i++){    //操作A,Bを累計i回行うことにする
        for(int j = 0; j <= i; j++){  //操作Aをj回行う
            for(int a = 0; a < j; a++) pq.push(V[a]); //左からj個
            for(int b = 0; b < i-j; b++) pq.push(V[N - 1 - b]); //右からi-j個
            int pop_n = 0;
            for(int k = 0; k < K - i; k++){
                if(pq.empty()) break;
                if(pq.top() >= 0) break;
                pq.pop();
            }
            int sum = 0, val;
            while(!pq.empty()){ val = pq.top(); sum += val; pq.pop(); }
            res = max(res, sum);
        }
    }

    cout << res << endl;
    return 0;
}