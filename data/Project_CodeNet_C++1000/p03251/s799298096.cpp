#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
 
int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    int rightx = -1000;
    int lefty = 1000;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        rightx = max(x, rightx);
    }
    for(int i=0; i<M; i++){
        int y;
        cin >> y;
        lefty= min(y, lefty);
    }
    if(rightx >= lefty){
        cout << "War" << endl;
        return 0;
    }
    else{
        if(min(Y,lefty)-max(X,rightx)>=1){
            cout << "No War" << endl;
        }
        else{
            cout << "War" << endl;
        }
    }
}