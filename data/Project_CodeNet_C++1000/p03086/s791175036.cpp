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
    int cnt=0;
    int longest=0 ;
    for(int i=0;i<size;i++){
        if( (S[i]=='A'||S[i]=='C') || (S[i]=='G'||S[i]=='T') ){
            cnt++;
            if(i==size-1){               // 最後の文字がA C G Tのどれかだとカウントされなくなってしまう。
                if(cnt > longest){
                    longest = cnt;
                }
            }
        }
        
        else{
            if( cnt > longest ){
                longest = cnt;
            }
            cnt = 0;
        }
    }
    cout << longest << endl;
}