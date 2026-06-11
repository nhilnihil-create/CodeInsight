#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool number753_checker(string num_str) {
    if (num_str.find("3") == string::npos) {
        return false;
    }
    if (num_str.find("5") == string::npos) {
        return false;
    }
    return num_str.find("7") != string::npos;
}

int solve(int n) {
    stack<string> targets;
    targets.push("3");
    targets.push("5");
    targets.push("7");
    int ans = 0;
    while (!targets.empty()) {
        string target_num = targets.top();
        targets.pop();

        if (stoll(target_num) > n) {
            continue;
        }

        if (number753_checker(target_num)) {
            ++ans;
        }
        targets.push(target_num + "3");
        targets.push(target_num + "5");
        targets.push(target_num + "7");
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}