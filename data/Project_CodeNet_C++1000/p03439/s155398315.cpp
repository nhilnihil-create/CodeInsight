#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    cout << 0 << endl;
    string prev_ans;
    cin >> prev_ans;
    if(prev_ans == "Vacant"){
        return 0;
    }
    int left = 0;
    int right = N;
    for(int i = 0; i < 19; i++){
        int mid = (left + right) / 2;
        cout << mid << endl;
        string ans;
        cin >> ans;
        if(ans == "Vacant"){
            return 0;
        }
        if(prev_ans == ans){
            if((mid - left + 1) % 2 == 0){
                right = mid;
            } else {
                left = mid;
                prev_ans = ans;
            }
        } else {
            if((mid - left + 1) % 2 == 1){
                right = mid;
            } else {
                left = mid;
                prev_ans = ans;
            }
        }
    }
    
    return 0;
}
