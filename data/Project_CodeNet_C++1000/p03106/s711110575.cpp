#include <iostream>
#include <stack>
using namespace std;

int main() {

    int A;
    int B;
    int K;

    cin >> A >> B >> K;

    int cnt = 0;

    stack<int> s;

    for (int i = 1; i <= 100; i++) {
        if(A % i == 0 && B % i == 0){
            s.push(i);
        }
    }

    for (int i = 0; i < K - 1; i++) {
        s.pop();
    }
    cout << s.top() << endl;

    return 0;

}