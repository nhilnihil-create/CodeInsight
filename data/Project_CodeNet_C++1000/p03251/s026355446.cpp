#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,X,Y;
    cin >> n >> m >> X >> Y;
    int max_x = -100;
    int x,y;
    int min_y = 100;
    for (int i = 0; i < n; i++){
        cin >> x;
        max_x = max(max_x,x);
    }
    for (int i = 0; i < m; i++){
        cin >> y;
        min_y = min(min_y,y);
    }
    if (min_y > max_x && max_x < Y && min_y > X){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }
}