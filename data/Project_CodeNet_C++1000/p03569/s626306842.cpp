#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

long long solve(string S){
    string T = "";
    for(auto c:S)if(c!='x')T+=c;
    string T2 = T;
    reverse(T2.begin(),T2.end());
    if(T!=T2)return -1;
    
    int N = T.size();
    vector<long long> nums(N+1,0);
    int iter = 0;
    for(int i = 0; i < S.size();){
        int j = i;
        while(j < S.size() && S[j] == 'x')j++;
        nums[iter++]=j-i;
        i = j+1;
    }
    
    long long res = 0;
    for(int i = 0; i*2 < nums.size();i++){
        res += max(nums[i],nums[(int)nums.size()-i-1])
            -  min(nums[i],nums[(int)nums.size()-i-1]);
    }
    
    return res;
    
}


int main(){
    string S;
    while(cin >> S)cout << solve(S) <<endl;
    
    
}


