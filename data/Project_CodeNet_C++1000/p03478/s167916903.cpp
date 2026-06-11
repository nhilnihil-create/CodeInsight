#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int N,a,b;
    cin >> N >> a >> b;
    vector<int> nums;
    for(int i=1; i<=N; i++){
        int temp = i;
        deque<int> digit;
        while(temp>0){
            digit.push_front(temp%10);
            temp/=10;
        }
        int sum = accumulate(digit.begin(),digit.end(),0);
        if(sum>=a && sum<=b){
            nums.push_back(i);
        }
    }
    int ans = accumulate(nums.begin(),nums.end(),0);
    cout << ans <<endl;
}