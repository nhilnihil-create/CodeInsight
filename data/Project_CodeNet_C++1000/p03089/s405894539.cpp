#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ori;
vector<int> res;
bool flag = true;

void check(int N) {
    // KEEP MOVING UNTIL ORIGINAL VECTOR IS EMPTY
    while(ori.empty() == false && flag == true) {
        // CHECK FROM THE BACK FOR THE RIGHT-MOST (THAT IS IN CORRECT POSITION)
        for(int i=ori.size()-1; i>=0; i--) {
            if(ori[i] == i) {
                res.push_back(i);
                ori.erase(ori.begin()+i);
                break;
            }
            else if(ori[i] > i) {
                flag = false;
            }
        }
    }
}

void output(int N) {
    // check for impossible case (-1)
    if(flag == false) cout << -1 << endl;
    else {
        reverse(res.begin(), res.end());
        for(int i=0; i<res.size(); i++) {
            cout << res[i] + 1 << endl;
        }
    }
}

int main() {
    int N, num;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> num;
        ori.push_back(num-1);
    }
    check(N);
    output(N);
}