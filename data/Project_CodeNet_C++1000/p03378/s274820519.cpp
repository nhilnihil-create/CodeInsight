#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, X;
    cin >> N >> M >> X;
    int cost1=0, cost2=0;
    int a;
    for(int i=0; i<M; i++){
        cin >> a;
        if(a<X) cost1++;
        else cost2++;
    }
    cout << min(cost1,cost2) << endl;
}