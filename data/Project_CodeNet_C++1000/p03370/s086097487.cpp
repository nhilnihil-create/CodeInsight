#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

using namespace std;
 
int main(){
    int A,B;
    cin >> A >> B;
    vector<int> S(A);
    for(int i = 0; i < A; i++){
        cin >> S.at(i);
    }
    int sum = B;
    int count = 0;

    sort(S.begin(), S.end());
    for(int i = 0; i < A; i++){
        sum -= S.at(i);
        count++;
    }
    if(sum >= S.at(0)){
        count = count + (sum/S.at(0));
    }
    cout << count << endl;
}