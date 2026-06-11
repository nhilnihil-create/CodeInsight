#include <iostream>
#include <string>
using namespace std;

int main() {

    int N;
    int A;
    int B;

    int sum = 0;
    string n_str;

    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++) {

        n_str = to_string(i);

        //cout << "n_str: " <<  n_str << endl;

        int tmp = 0;
        for (int j = 0; j < n_str.size(); j++) {

            tmp = tmp + (int)n_str[j] - 48;
            //cout << "tmp: " << tmp << endl;
        }

        if (tmp >= A && tmp <= B){
            sum = sum + i;
        }
    }

    cout <<  sum << endl;

    return 0;

}