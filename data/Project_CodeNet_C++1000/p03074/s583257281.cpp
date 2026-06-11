#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    long long n, K;
    cin >> n >> K;
    string s;
    cin >> s;
    vector<long long> nums;

    if(s[0] == '0'){
        nums.push_back(0);
    }

   
    for (long long i = 0; i < s.size();) {
        long long j = i;
        while (j < s.size() && s[j] == s[i]) ++j; // S[i] の数値がどこまで続くか
        nums.push_back(j - i);
        i = j;
    }

    if(s.back() == '0'){
        nums.push_back(0);
    }

    vector<long long> sums(nums.size()+1, 0);

    for(long long k = 0; k < nums.size(); k++){
        sums[k+1] = sums[k] + nums[k];
    }

    long long maxv = 0;

    /*for(long long k = 0; k <= n; k += 2){
       
        if(k+2*K+1 > n){
            maxv = max(maxv, sums[n]-sums[k]);
        }
        else{
            maxv = max(maxv, sums[k+2*K+1]-sums[k]);
        }
        
    }*/

    for (long long left = 0; left < sums.size(); left += 2) {
        long long right = left + K*2+1;
        if (right >= sums.size()) right = sums.size() - 1;
        maxv = max(maxv, sums[right] - sums[left]);
    }

    cout << maxv << endl;
    return 0;
}
