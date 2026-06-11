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
    int A,B;
    cin >> A >> B ;
    string S;
    cin >> S;
    int total = A + B + 1;
    for(int i=0;i<total;i++){
        if(i==A){
            if(S[i]!='-'){
                cout << "No" << endl;
                break;
            }
        }
        else if((S[i] < '0')||(S[i] > '9') ){
            cout << "No" << endl;
            break;
        }
        else if(i== total - 1){
            cout << "Yes" << endl;
        }
    }
}