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
    int N;
    cin >> N;
    vector<string> W(N);
    bool frg = false;
    for(int i=0;i<N;i++){
        cin >> W[i];
        if(i!=0){
            int size= W[i-1].size();
            if(W[i][0]!=W[i-1][size-1]){
                cout << "No" << endl;
                break;
            }
            for(int j=0;j<i;j++){
                if(W[i]==W[j]){
                    frg = true;
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if(frg){
            break;
        }
        if(i==N-1){
            cout << "Yes" << endl;
        }
    }
}