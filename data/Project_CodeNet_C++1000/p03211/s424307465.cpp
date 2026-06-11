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
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    string S;
    cin >> S;
    int n = S.size();
    vector<int> num(n-2);
    for(int i=0;i<(n-2);i++){
        string test;
        test[0]=S[i];
        test[1]=S[i+1];
        test[2]=S[i+2];
        int num_1 = stoi(test);
        num[i] = num_1;
    }
    int min_diff;
    int diff;
    for(int i=0;i<n-2;i++){
        diff = abs(num[i] - 753);
        if(i==0){
            min_diff = diff;
        }
        else if(min_diff > diff){
            min_diff = diff;
        }
    }
    cout << min_diff << endl;
}