#include<iostream>
#include<vector>
using namespace std;

int mini_ans[5] = {2, 5, 20, 30, 63};

int main() {
    int N;
    cin >> N;
    if (N <= 5) {
        for (int i = 0; i < 5; i++) {
            if (N == 3) {
                if (i != 2 && i != 3) cout << mini_ans[i] << ' ';
            }
            else if (N == 4) {
                if (i != 3) cout << mini_ans[i] << ' ';
            }
            else cout << mini_ans[i] << ' ';
        }
        cout << endl;
        return 0;
    }
    vector<int> ans;
    int k = 0, sum = 0;
    int plus_num[4] = {2, 3, 4, 6};
    for (int i = 0; i < N / 4; i++) {
        for (int j = 0; j < 4; j++) {
            ans.push_back(6 * k + plus_num[j]);
            sum += 6 * k + plus_num[j];
        }
        k++;
    }
    for (int i = 0; i < N % 4; i++) {
        ans.push_back(6 * k + plus_num[i]);
        sum += 6 * k + plus_num[i];
    }
    if (sum % 6 == 0) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
    }
    else if (sum % 6 == 2) {
        ans.push_back(6 * k + 6);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != 8) {
                cout << ans[i] << ' ';
            }
        }
    }
    else if (sum % 6 == 3) {
        ans.push_back(6 * k + 6);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != 9) {
                cout << ans[i] << ' ';
            }
        }
    }
    else if (sum % 6 == 5) {
        if (N % 4 >= 2) k++;
        ans.push_back(6 * k + 4);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != 9) {
                cout << ans[i] << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}