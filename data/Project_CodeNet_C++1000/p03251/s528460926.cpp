#include "bits/stdc++.h"
using namespace std;

int main(){
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    int x[N];
    int y[M];
    for(int i=0;i<N;i++) cin >> x[i];
    for(int i=0;i<M;i++) cin >> y[i];
    sort(x,x+N);
    sort(y,y+M);
    if(x[N-1]<y[0] && y[0]>X && x[N-1]<Y) cout << "No War" << endl;
    else cout << "War" << endl;
}




