#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int N,Y;
    cin >> N >> Y;
    int i,j,k;
    bool finished = false;
    for(i=0;i<=N;i++){
        for(j=0;j<=(N-i);j++){
            k = N -(i+j);
            if( 1000*i+5000*j+10000*k == Y){
                finished = true;
                break;
            }
        }
        if(finished){break;}
    }
    if(finished){
        cout << k << " " << j << " " << i <<endl;
    }
    else{
        cout << -1 << " " << -1 << " " << -1 <<endl;
    }
}
    