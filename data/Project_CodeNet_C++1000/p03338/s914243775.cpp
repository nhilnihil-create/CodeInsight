#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    //
    vector<int> abc0(26,0);
    vector<int> abc1(26,0);
    //
    int common=0;
    int most=0;
    //
    for(int i=1;i<N;i++){
        common=0;
        vector<int> abc0(26,0);
        vector<int> abc1(26,0);
        for(int j=0;j<i;j++){
            int num0 = (int)(S[j]-'a');
            abc0[num0]++;
        }
        for(int k=i;k<N;k++){
            int num1 = (int)(S[k]-'a');
            abc1[num1]++;
        }
        for(int l=0;l<26;l++){
            if((abc0[l]>=1)&&(abc1[l]>=1)){
                common++;
            }
        }
        if(common > most){
            most = common;
        }
    }
    cout << most << endl;
}