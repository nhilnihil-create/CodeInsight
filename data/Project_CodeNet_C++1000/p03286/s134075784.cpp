#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;

int main(){
    long long n, md = 1;
    cin >> n;
    vector<int> ans;
    if(!n) cout << 0;
    while(n){
        if(!(n % 2)){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
            n--;
        }
        n /= -2;
    }
    for(int i = ans.size() - 1; i >= 0; --i) cout << !ans[i];
}