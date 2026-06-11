#include <bits/stdc++.h>
using namespace std;
 
int main() {

    int N;
    cin >> N;
    vector<char>S(N);
    vector<long long>count(5,0);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.at(i) = s.at(0);
        if (S.at(i) == 'M'){
            count.at(0)++;
        }
        else if (S.at(i) == 'A'){
            count.at(1)++;
        }
        else if (S.at(i) == 'R'){
            count.at(2)++;
        }
        else if (S.at(i) == 'C'){
            count.at(3)++;
        }
        else if (S.at(i) == 'H'){
            count.at(4)++;
        }
    }

    long long sum = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 4; j++) {
            for (int k = j+1; k < 5; k++) {
                sum += count.at(i) * count.at(j) * count.at(k);
            }
        }
    }

    cout << sum << endl;
}