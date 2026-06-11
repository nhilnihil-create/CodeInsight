#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int left,right;
    int water = 0;
    cin >> N;

    vector<int> h(N);
    for(int i=0;i<N;i++) {
        cin >> h[i];
    }

    left= 0;
    while(1) {
        while(h[left] == 0) {
            left++;
            if(left == N)break;
        }
        if(left == N)break;
        right = left + 1;
        if(right != N) {
            while(h[right]) {
                right++;
                if(right == N)break;
            }
        }
        if(right > left) water++;
        for(int i=left;i<right;i++) {
            h[i]--;
        }
        if(left == N)break;
    }

    cout << water << endl;
    return 0;
}
