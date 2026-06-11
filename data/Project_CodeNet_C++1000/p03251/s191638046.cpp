#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    //vector<int> xs(n), ys(n);
    int max = x, min = y;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp > max) max = tmp;
    }
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        if(tmp < min) min = tmp;
    }

    if(max < min) cout << "No War" << endl;
    else          cout << "War" << endl;
    

    

}