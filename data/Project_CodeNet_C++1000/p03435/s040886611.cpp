#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> T(3, vector<int>(3, 0));
    for (int i=0; i<3; i++) for (int j=0; j<3; j++) cin>>T[i][j];

    vector<int> a(3, 0), b(3, 0);
    b[0] = T[0][0];
    b[1] = T[0][1];
    b[2] = T[0][2];
    a[1] = T[1][0] - b[0];
    a[2] = T[2][0] - b[0];

    bool flg = true;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (T[i][j] != a[i] + b[j]) {
                flg = false;
                break;
            }
        }
    }

    flg ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    return 0;
}
