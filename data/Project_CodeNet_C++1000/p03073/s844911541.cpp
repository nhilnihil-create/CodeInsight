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
    int size = S.size();
    vector<char> str(size);
    for(int i=0;i<size;i++){
        str[i]=S[i];
    }
    // first black 0
    vector<char> black_first(size);
    for(int i=0;i<size;i++){
        if(i%2==0){
            black_first[i]='0';
        }
        else{
            black_first[i]='1';
        }
    }
    // first white 1
    vector<char> white_first(size);
    for(int i=0;i<size;i++){
        if(i%2==0){
            white_first[i]='1';
        }
        else{
            white_first[i]='0';
        }
    }
    //
    int requireB=0;
    int requireW=0;
    for(int i=0;i<size;i++){
        if(str[i]!=white_first[i]){
            requireW++;
        }
        if(str[i]!=black_first[i]){
            requireB++;
        }
    }
    int ans = min(requireB, requireW);
    //
    cout << ans << endl;
}