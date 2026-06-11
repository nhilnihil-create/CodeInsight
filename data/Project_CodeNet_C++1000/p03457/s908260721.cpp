#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N;
    cin >> N;
    vector<vector<int>> data(N+1,vector<int>(3));
    for (int i=1; i<N+1; i++) {
        for (int j=0; j<3; j++) {
            cin >> data.at(i).at(j);
        }
    }

    //
    vector<int> t(N+1);
    vector<int> X(N+1);
    for (int i=0; i<N+1; i++) {
        t.at(i) = data.at(i).at(0);
        X.at(i) = data.at(i).at(1) + data.at(i).at(2);
    }

    for (int i=1; i<N+1; i++) {
        if (abs(X.at(i)-X.at(i-1)) > t.at(i)-t.at(i-1)) {
            cout << "No" << endl;
            exit(0);
        }
        else if (abs((X.at(i)-X.at(i-1)))%2 != (t.at(i)-t.at(i-1))%2) {
            cout << "No" << endl;
            exit(0);
        }
    }

    cout << "Yes" << endl;
}