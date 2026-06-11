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
    cin >> N >> M;
    
    if(M < N){
        N = M;
    }

    vector<long> point;
    vector<long> dis;

    for(int i =0; i < M; i++){
        long tmp;
        cin >> tmp;
        point.push_back(tmp);
    }

    sort(point.begin(), point.end());
    long sum = 0;
    for(int i =0; i < M-1; i++){
        long tmp_dis = point[i+1] - point[i];
        dis.push_back(tmp_dis);
        sum += tmp_dis;
    }
    sort(dis.begin(), dis.end(), std::greater<long>());
    long aima = 0;
    for(int i =0; i < N-1; i++){
        aima += dis[i];
    }
    cout << sum - aima << endl;
    return 0;
}

