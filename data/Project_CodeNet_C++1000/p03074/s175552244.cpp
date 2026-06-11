#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,k;    cin>>n>>k;
    string s;   cin>>s;
    vector<int>dic;
    if(s.front() == '0') dic.push_back(0);
    int tmp = 0;
    rep(i, n){
        if(s[i] != s[tmp]){
            dic.push_back(i-tmp);
            tmp = i;
        }
    }
    dic.push_back(n-tmp);
    if(s.back() == '0') dic.push_back(0);
    int len = 2*k+1;
    //[l, r)
    int l = 0, r = len;
    int sum = 0;
    rep(i, len){
        if(i>=dic.size())   break;
        sum += dic[i];
    }
    int ans = sum;
    for(; r < dic.size();){
        sum = sum + dic[r] - dic[l];
        r++;
        l++;
        sum = sum + dic[r] - dic[l];
        r++;
        l++;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
