#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int GCD(int a,int b){
    if(b == 0)return a;
    return GCD(b,a%b);
}
int main(void){
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    int x[N],y[M];
    for(int i=0;i<N;i++)cin>>x[i];
    for(int i=0;i<M;i++)cin>>y[i];
    sort(x,x+N);
    sort(y,y+M);
    int max_x = x[N-1];
    int min_y = y[0];
    if(max_x < min_y && max_x < Y && min_y > X){
        cout << "No War" << endl;
    }
    else{
        cout << "War" << endl;
    }
}
