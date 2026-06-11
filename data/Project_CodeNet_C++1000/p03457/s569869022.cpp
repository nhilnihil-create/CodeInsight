#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int t, x, y;
    int x_pre = 0;
    int y_pre = 0;
    int t_pre = 0;
    bool ans = true;
    for(int i=0; i<N; i++){
        cin >> t >> x >> y;
        int mrg = t - t_pre - (abs(x - x_pre) + abs(y - y_pre));
        if(mrg >= 0 && mrg % 2 == 0){
            ;
        }
        else{
            ans = false;
        }
        t_pre = t;
        x_pre = x;
        y_pre = y;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}