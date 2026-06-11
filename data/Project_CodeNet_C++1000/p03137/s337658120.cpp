#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N,M;
    cin >> N >> M;
    int X[M];
    for(int i=0;i<M;i++){
        cin >> X[i];
    }
    int distance[M];
    distance[M-1] = 0;
    sort(X,X+M);
    for(int i=0;i+1<M;i++){
        distance[i] = X[i+1] - X[i];
    }
    int ans = 0;
    sort(distance,distance+M,greater<>());
    for(int i=N-1;i<M;i++){
        ans += distance[i];
    }
    cout << ans << endl;
}
