#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long int ans = 0;
    map<long long int, int> memo;
    long long int sum = 0;
    memo[0] = 1;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(memo.count(sum) == 0){
            memo[sum] = 1;
        }else{
            memo.at(sum)++;
        }
    }
    
    for(auto p: memo){
        if(p.second >= 2){
            long long int q = p.second;
            ans += q*(q-1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}