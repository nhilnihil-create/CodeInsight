#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int A=4,B=7,C=28;
    string ans;
    bool memo[101] = {false};
    for(int i=0;i<=100;i+=A){
        for(int j=i;j<=100;j+=B){
            memo[j] = true;
        }
    }
    
    if(memo[N]){
        ans = "Yes";
    }
    else{
        ans = "No";
    }
    
    cout << ans << endl;
}
