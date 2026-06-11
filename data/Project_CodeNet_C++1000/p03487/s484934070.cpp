#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int input, ans = 0;
    cin >> input ;
    
    vector<int> cnt(input + 2);
    int num;
    
    for(int i = 0; i < input; i++){
        cin >> num;
        if(num <= input){
            cnt.at(num)++;
        } else {
            cnt.at(input + 1)++;
            ans++;
        }
    }
    
    for(int i = 0; i <= input; i++){
        if(cnt.at(i) < i){
            ans += cnt.at(i);
        } else if (cnt.at(i) > i){
            ans += cnt.at(i) - i;
        }
    }
    
    cout << ans << endl;
    
    return 0;    
}
