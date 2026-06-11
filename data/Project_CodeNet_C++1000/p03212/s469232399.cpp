#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;
long long ans;
long long N;
bool number(int n){
    int count3=0,count5=0,count7=0;
    while(n > 0){
        int r = n % 10;
        if(r == 3)count3++;
        else if(r == 5)count5++;
        else if(r == 7)count7++;
        else return false;
        n /= 10;
    }
    return count3 && count5 && count7;
}
void solve(long long s){
    if(s > N){
        return;
    }
    if(number(s)){
        ans++;
    }
    for(int i=3;i<=7;i+=2){
        solve(s * 10 + i);
    }
    return;
}
int main(void){

    cin >> N;
    solve(0);
    cout << ans;
}
