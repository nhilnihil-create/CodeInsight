#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int tmp_x = 0;
    int tmp_y = 0;
    int result;

    cin >> n;

    vector <int> v(n);
    vector <int> c(n);

    int tmp = 0;
    int i = 0;
    while(cin >> tmp) {
        v[i] = tmp;
        i ++;
        if(i >= n){
            break;
        }
    }

    i = 0;

    while(cin >> tmp) {
        c[i] = tmp;
        i ++;
        if(i >= n){
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        if(v[i] > c[i]) {
            tmp_x += v[i];
            tmp_y += c[i];
        }
    }

    cout << tmp_x - tmp_y << endl;


}