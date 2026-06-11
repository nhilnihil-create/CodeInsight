#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> h(6);
    int k;
    int flag = 0;

    int tmp = 0;
    int i = 0;
    while(cin >> tmp) {
        h[i] = tmp;
        i ++;
        if(i >= 6) {
            break;
        }
    }

    k = h[5];

    for(int i = 0; i < 5; i++) {
        for(int j = i+1; j < 5; j++) {
            if( (h[j] - h[i]) > k ) {
                flag = 1;
            }
        }
    }

    if(flag == 1) {
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    }


}
