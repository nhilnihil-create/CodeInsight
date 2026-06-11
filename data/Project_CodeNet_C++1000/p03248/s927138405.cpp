#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

int v_count;

int print_edge(int s){
    printf("%d %d\n", s, v_count);
    v_count ++;
}

int main(){ 
    string S;
    cin >> S;
    int N = S.size();
    int cur_no = 1;
    if(S[N - 1] == '1' || S[0] == '0' || S[N - 2] == '0'){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < N / 2; i++){
        if(S[i] != S[N - 2 - i]){
            cout << - 1 << endl;
            return 0;
        }
    }
    int biggest = 0;
    for(int i = N / 2 - 1; i >= 0; i--){
        if(S[i] == '1'){
            biggest = i + 1;
            break;
        }
    }
    cout << 1 << " " << 2 << endl;;
    v_count = 3;
    for(int i = 0; i < N - biggest - 1; i++){
        print_edge(2);
    }

    int cur_v = 1;
    int last_component_size = biggest;
    for(int i = biggest - 2; i >= 0; i--){
        if(S[i] == '1'){
            for(int j = 0; j < last_component_size - (i + 1) - 1; j++){
                print_edge(cur_v);
            }
            int tmp = cur_v;
            cur_v = v_count;
            last_component_size = i + 1;
            print_edge(tmp);
        }
    }
    return 0;
}