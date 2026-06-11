#include <iostream>
using namespace std;
int main(void){
    int a, b;
    char s[100][100];
    cin >> a >> b;
    
    for (int i = 0; i < 50; i++) fill(s[i], s[i] + 100, '#');
    for (int i = 50; i < 100; i++) fill(s[i], s[i] + 100, '.');
    
    a--;  b--;
    int h = 0, w = 0;
    while (a != 0) {
        s[h][w] = '.';  w += 2;
        if (w == 100) {
            h += 2;  w = 0;
        }
        a--;
    }
    h = 51, w = 0;
    while (b != 0) {
        s[h][w] = '#';  w += 2;
        if (w == 100) {
            h += 2;  w = 0;
        }
        b--;
    }
    
    cout << "100 100" << endl;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) cout << s[i][j];
        cout << endl;
    }
    
}
