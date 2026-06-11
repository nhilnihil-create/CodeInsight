#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 左に落ちたら-1, 右に落ちたら1, 落ちなかったら0
int trace(string s, const vector<char> &t, const vector<char> &d, int k){

    char current_masu = s[k];
    for(int i = 0; i < t.size(); i++){
        if(current_masu == t[i]){
            if(d[i] == 'L') k--;
            else k++;
            current_masu = s[k];
        }     
    }
    
    if(k < 0) return -1;
    else if(k >= s.length()) return 1;
    else return 0;
}

int main(){

    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<char> t(Q), d(Q);
    for(int i = 0; i < Q; i++) cin >> t[i] >> d[i];

    int min = 0, max = N;
    int left = min;
    while(min <= max){
        int half = (min + max + 1) / 2;
        if(trace(s, t, d, half) == -1){
            min = half + 1;
            left = std::max(left, half);
        }else{
            max = half - 1;
        }
    }

    min = 0, max = N;
    int right = max;
    while(min <= max){
        int half = (min + max + 1) / 2;
        if(trace(s, t, d, half) == 1){
            max = half - 1;
            right = std::min(right, half);
        }else{
            min = half + 1;
        }
    }

    if(right - left - 1 < 0) cout << 0 << endl;
    else cout << right - left - 1 << endl;

    return 0;
}