#include <bits/stdc++.h>
using namespace std;

void test(string ABCD, string op, string &answer){
    if(op.size() == 3){
        int sum = ABCD.at(0) - '0';

        for(int i = 0; i < 3; i++){
            if(op.at(i) == '+') sum += ABCD.at(i+1) - '0';
            if(op.at(i) == '-') sum -= ABCD.at(i+1) - '0';
        }

        if(sum == 7) answer = op;
    }

    if(0 <= op.size() && op.size() < 3){
        op.push_back('+');
        test(ABCD, op, answer);
        op.pop_back();

        op.push_back('-');
        test(ABCD, op, answer);
        op.pop_back();
    }
}

int main() {
    string ABCD;
    cin >> ABCD;

    string op = "";
    string answer;
    test(ABCD, op, answer);

    cout << ABCD.at(0);
    for(int i = 0; i < 3; i++){
        cout << answer.at(i) << ABCD.at(i+1);
    }
    cout << "=7" << endl;
}
