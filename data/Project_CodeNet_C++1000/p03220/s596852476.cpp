#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, t, a, h;

    cin >> n;
    cin >> t >> a;
    int  ans = 0;
    double min;
    for(int i = 0; i < n; i++){
        cin >> h;
        double tmp = t - h*0.006;
        if(i == 0){
            ans = 0;
            min = abs(tmp-a);
        }else{
            if(min > abs(tmp-a)){
                min = abs(tmp-a);
                ans = i;
            }
        }
    }

    cout << (ans+1) << endl;
}