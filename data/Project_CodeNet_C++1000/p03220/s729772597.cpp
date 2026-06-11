#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <map>
#include <utility>

using namespace std;

int main(){
    int_least64_t n;
    cin >> n;
    float t, a;
    cin >> t;
    cin >> a;
    float h[n];
    float ans[n];
    float c = 0.006;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        ans[i] = abs(a - (t - (h[i]*c)));
        //cout << ans[i] << endl;
    }

    int min = 0;

    for(int i = 0; i < n; i++){
        if(ans[i] < ans[min]){
            min = i;
        }
    }

    cout << min + 1 << endl;

}