#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <limits.h>
#include <float.h>
#include <numeric>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int myabs(int x){
    if(x < 0){
        x = -x;
    }
    return x;
}

vector<int> x_num, y_num;

int main(){
    string s;
    int x, y;
    cin >> s;
    cin >> x >> y;
    int len = s.length();

    int start = 0;
    while(s[start] == 'F' && start < len){
        x--;
        start++;
    }

    int dir = 0;
    int tmp = 0;
    for(int i = start; i < len; i++){
        if(s[i] == 'T'){
            if(tmp > 0){
                if(dir == 0){
                    x_num.push_back(tmp);
                }
                else{
                    y_num.push_back(tmp);
                }
                tmp = 0;
            }
            dir = 1 - dir;
        }
        else{
            tmp++;
        }
    }
    if(tmp > 0){
        if(dir == 0){
            x_num.push_back(tmp);
        }
        else{
            y_num.push_back(tmp);
        }
    }

    int x_value[2][8100], y_value[2][8100];
    fill(x_value[0], x_value[0]+8100, 0);
    fill(y_value[0], y_value[0]+8100, 0);
    fill(x_value[1], x_value[1]+8100, 0);
    fill(y_value[1], y_value[1]+8100, 0);

    x_value[0][0] = 1; y_value[0][0] = 1;
    int x_sum = 0, y_sum = 0;
    for(int i = 0; i < x_num.size(); i++){
        x_sum += x_num[i];
        for(int j = 0; j < x_num[j]; j++){
            x_value[1][j] = x_value[0][j];
        }
        for(int j = x_num[i]; j < 8100; j++){
            x_value[1][j] = max(x_value[0][j-x_num[i]], x_value[0][j]);
        }
        for(int j = 0; j < 8100; j++){
            x_value[0][j] = x_value[1][j];
        }

    }
    for(int i = 0; i < y_num.size(); i++){
        y_sum += y_num[i];
        for(int j = 0; j < y_num[j]; j++){
            y_value[1][j] = y_value[0][j];
        }
        for(int j = y_num[i]; j < 8100; j++){
            y_value[1][j] = max(y_value[0][j-y_num[i]], y_value[0][j]);
        }
        for(int j = 0; j < 8100; j++){
            y_value[0][j] = y_value[1][j];
        }
    }

    if(x_sum - myabs(x) < 0 || y_sum - myabs(y) < 0){
        cout << "No" << endl;
    }
    else if((x_sum - myabs(x)) % 2 == 1 || (y_sum - myabs(y)) % 2 == 1){
        cout << "No" << endl;
    }
    else if(x_value[0][(x_sum - myabs(x))/2] == 1 && y_value[0][(y_sum - myabs(y))/2] == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }


    return 0;
}
