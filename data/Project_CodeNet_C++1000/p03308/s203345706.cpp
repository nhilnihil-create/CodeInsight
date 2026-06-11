#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    int min = 2000000000;
    int max = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec.at(i);

    for (int i = 0; i < n; i++){
        if (vec.at(i)<min){
            min = vec.at(i);
        }
        if (vec.at(i)>max){
            max = vec.at(i);
        }
    }
    int ans = abs(max-min);
    cout << ans << endl;

}