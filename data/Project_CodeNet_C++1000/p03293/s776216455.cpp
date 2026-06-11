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
    string S,T;
    cin >> S >> T;
    int N = S.size();
    for(int i=0;i<N;i++){
        string s = S;
        for(int j=0;j<N;j++){
            if(j-i>=0){
                s[j-i] = S[j];
            }
            else{
                int num = abs(j-i);
                s[N-num]=S[j];
            }
        }
        if(s==T){
            cout << "Yes" << endl;
            break;
        }
        else if(i==N-1){
            cout << "No" <<endl;
        }
    }
}