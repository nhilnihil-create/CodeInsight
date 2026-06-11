#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n, m, x, y;

    cin >> n; 
    cin >> m;
    cin >> x; 
    cin >> y;

    int _x[n];
    int _y[m];

    for(int i = 0; i < n ;i++){
        cin >> _x[i];
    }

    for(int i = 0; i < m; i++){
        cin >> _y[i];
    }

    sort(_x, _x+n);
    sort(_y, _y+m);

    int c = _y[0];

    int flag = 0;

    if(_x[n-1] < c){
        flag++;
    }
    if(_y[0] >= c){
        flag++;
    }

    if(x<c && c <= y){
        flag ++;
    }

    if(flag == 3){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }
}