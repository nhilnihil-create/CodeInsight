#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int ans;
    for(int i=N;i<=999;i++){
        if(i % 111 == 0){
            ans = i;
            break;
        }
    }
    cout << ans;
}
