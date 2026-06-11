#include <iostream>
#include<iomanip>
#include <climits>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


char t[200000];
char d[200000];
string s;

int move(char c){
    if(c == 'R'){
        return 1;
    } else {
        return - 1;
    }
}

bool disappear_from_left(int pos, int Q){
    int cur = pos;
    for(int i = 0; i < Q; i++){
        if(s[cur] == t[i]){
            cur += move(d[i]);
        }
        if(cur > (int) s.size() - 1){
            return false;
        }
        if(cur < 0){
            return true;
        }
    }
    return false;
}

bool disappear_from_right(int pos, int Q){
    int cur = pos;
    for(int i = 0; i < Q; i++){
        if(s[cur] == t[i]){
            cur += move(d[i]);
        }
        if(cur < 0){
            return false;
        }
        if(cur > (int) s.size() - 1){
            return true;
        }
    }
    return false;
}


int main(){
    
    int N;
    int Q;
    cin >> N >> Q;
    cin >> s;

    for(int i = 0; i < Q; i++){
        cin >> t[i] >> d[i];
    }

    int left = 0;
    int right = N - 1;
    int right_most_disappear_left;
    if(disappear_from_left(right, Q)){
        cout << 0 << endl;
        return 0;
    } else if(!disappear_from_left(left, Q)){
        right_most_disappear_left = -1;
    } else {
        while(left + 1 < right){
            int mid = (left + right) / 2;
            if(disappear_from_left(mid, Q)){
                left = mid;
            } else {
                right = mid;
            }
        }
        right_most_disappear_left = left;
    }

    left = 0;
    right = N - 1;
    int left_most_disappear_right;
    if(disappear_from_right(left, Q)){
        cout << 0 << endl;
        return 0;
    } else if(!disappear_from_right(right, Q)){
        left_most_disappear_right = N;
    } else {
        while(left + 1 < right){
            int mid = (left + right) / 2;
            if(disappear_from_right(mid, Q)){
                right = mid;
            } else {
                left = mid;
            }
        }
        left_most_disappear_right = right;
    }

    //cout << right_most_disappear_left << " " << left_most_disappear_right << endl;
    cout << max(0, N - (N - left_most_disappear_right) - (right_most_disappear_left + 1)) << endl; 
    return 0;
}