#include<bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> X(M);
    for(int i=0; i<M; i++){
        cin >> X[i];
    }
    
    sort(X.begin(), X.end(), greater<int>());

    vector<int> dis;
    for(int i=0; i<M-1; i++){
        dis.push_back(X[i]-X[i+1]);
    }

    sort(dis.begin(), dis.end(), greater<int>());

    int res = X[0] - X.back();

    for(int i=0; i<min((int)dis.size(), N-1); i++){
        res -= dis[i];
    }

    cout<< res <<endl;
    return 0;
}