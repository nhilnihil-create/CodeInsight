#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;

vector<int> cost(1000000);
vector<vector<int>> data(1000000);

// 10進数を1桁ずつに分割して、配列にして返す
vector<int> divide(string str){
    vector<int> divide(str.length());
    for(int i = 0; i < str.length(); i++){
        divide.at(i) = str.at(i) - '0';
    }
    return divide;
}

int main(){
    string n;
    cin >> n;
    vector<int> divided = divide(n);
    
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<3); ++bit)
    {
        /* bit で表される集合の処理を書く */
        bitset<3> tmp(bit);
        int answer = divided.at(0);
        /* bit で表される集合の処理を書く */
        for(int i = 0; i < 3; i++){
            if(tmp.test(i)) {
                answer += divided.at(i+1);
            }
            else {
                answer -= divided.at(i+1);
            }
        }

        if(answer == 7) {
            for(int i = 0; i < 3; i++){
                cout << divided.at(i);
                if(tmp.test(i)) cout << '+';
                else cout << '-';
            }
            cout << divided.at(3) << "=7" << endl;
            break;
        }
    }
}