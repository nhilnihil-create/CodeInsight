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
    if(S[0]!='A'){
        cout << "WA" << endl;
    }
    else{
        int cnt=0;
        int num;
        bool frg = true;
        for(int i=2;i<size-1;i++){
            if(S[i]=='C'){
                cnt++;
                num= i;
            }
        }
        if(cnt!= 1){
                    cout << "WA" << endl;
                    frg = false;
                }
        if(frg){
            for(int i=1;i<size;i++){
                if(i!=num){
                    if(('a'> S[i])||(S[i] > 'z')){
                        cout<< "WA" << endl;
                        break;
                    }
                }
                if(i==size-1){
                    cout << "AC" << endl;
                }
            }
        }
        
    }
}