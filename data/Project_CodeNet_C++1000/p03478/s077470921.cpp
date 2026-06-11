#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;

    for (int i = 0; i <= N; i++) {
        //cout << "case: i = " << i << endl;
        string str_i = to_string(i);
        int sum_i = 0;
        for (int j = 0; j < str_i.size(); j++)
            sum_i += str_i.at(j) - '0';
        
        if (A <= sum_i && sum_i <= B) {
            sum += i;
            //cout << "+" << i << endl;
        }
    }
    cout << sum << endl;
}