#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


int MAX_INDEX = 40;

string create(long long val, vector<long long>& max_table, vector<long long>& min_table, vector<long long>& pow_table){
    if(val == 0){
        return "0";
    }

    int index = 0;

    for(; index < MAX_INDEX; ++index){
        if(min_table[index] <= val && val <= max_table[index]){
            break;
        }
    }

    if(index % 2 == 0){
        val -= pow_table[index];
    }
    else{
        val += pow_table[index];
    }

    if(val == 0){
        string ret = "1";
        for(int i = 1; i < index + 1; ++i){
            ret += "0";
        }
        return ret;
    }

    string sub = create(val, max_table, min_table, pow_table);
    string ret = "1";

    for(int i = 1; i < index - sub.size() + 1; ++i){
        ret += "0";
    }

    return ret + sub;
}


int main(){
    long long N;
    cin >> N;

    vector<long long> max_table(MAX_INDEX);
    vector<long long> min_table(MAX_INDEX);
    vector<long long> pow_table(MAX_INDEX);

    pow_table[0] = 1;
    pow_table[1] = 2;

    max_table[0] = 1;
    max_table[1] = -1;

    min_table[0] = 0;
    min_table[1] = -2;

    long long val = 2;

    for(int i = 2; i < MAX_INDEX; ++i){
        val *= 2;
        pow_table[i] = val;

        if(i % 2 == 0){
            max_table[i] = max_table[i - 2] + val;
            min_table[i] = min_table[i - 1] + val;
        }
        else{
            max_table[i] = max_table[i - 1] - val;
            min_table[i] = min_table[i - 2] - val;
        }
    }

    cout << create(N, max_table, min_table, pow_table);
}
