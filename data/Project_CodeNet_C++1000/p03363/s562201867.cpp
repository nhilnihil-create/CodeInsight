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
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(memo.count(sum) == 0){
            memo[sum] = 1;
        }else{
            memo.at(sum)++;
        }
    }
    sum = 0;
    for(int i = 0; i < n; i++){
        if(memo.count(sum) > 0){
            ans += memo.at(sum);
        }
        sum += a[i];
        if(memo.count(sum) > 0){
            if(memo.at(sum) > 1) memo.at(sum)--;
            else memo.erase(sum);
        }
    }
    cout << ans << endl;
    return 0;
}