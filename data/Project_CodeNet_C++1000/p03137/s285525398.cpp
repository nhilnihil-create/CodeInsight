#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    
    vector<int> X(M);

    for (int i = 0; i < M; i++)
    {
        cin >> X[i];
    }
    
    sort(X.begin(), X.end());

    priority_queue<int> dist;
    
    for(int i = 0; i < M - 1; i++){
        dist.push(X[i+1]- X[i]);
    }

    for(int i = 0; i < N-1; i++){
        if(dist.empty()) break;
        int d = dist.top();
        dist.pop();
    }

    int sum = 0;
    while (!dist.empty())
    {
        sum+=dist.top();
        dist.pop();
    }

    cout << sum << endl;

    return 0;
}
