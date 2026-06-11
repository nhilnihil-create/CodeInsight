#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, j, num = 0;
    cin >> n;
    vector<int>    height(n, 0);
    for(int i = 0; i < n; i++)
        cin >> height.at(i);

    for(int i = 0; i < n;) {
        if(height.at(i) == 0) {
            i++; continue;
        }
        for(j = i; j < n; j++) {
            if(height.at(j) == 0) {
                 break;
            }
        }

        for(int k = i; k < j; k++) {
            height.at(k)--;
        }
        num++;
    }

    cout << num << endl;
}
    