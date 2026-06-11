#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <regex>
#include <initializer_list>
#include <deque> 
#define DBL_MIN 0.000000000000001

#include <iostream>
using namespace std;



int main(void){
    long N,M;
    cin >> N;
    map<int,int> good;
    for(int i = 0; i < N; i++){
        int tmp =~ 0;
        cin >> tmp;
        good[tmp]++;
    }

    int sum = 0;
    for(auto it = good.begin(); it != good.end(); ++it){
        if(it->first > it->second){
            sum += it->second;
        }else if(it->second > it->first){
            sum += it->second - it->first;
        }
    }
    cout << sum << endl;


    return 0;
}

