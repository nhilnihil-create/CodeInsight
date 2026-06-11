#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int l = 0, r = n;
    string left, right;
    cout << 0 << endl;
    fflush(stdout);
    cin >> left;
    right = left;
    while(true){
        string center;
        int c = (l + r) / 2;
        cout << c << endl;
        fflush(stdout);
        cin >> center;
        if(center == "Vacant") return 0;
        if(center == right){
            if((r - c) % 2){
                l = c;
                left = center;
            }
            else{
                r = c;
                right = center;
            }
        }
        else{
            if((r - c) % 2){
                r = c;
                right = center;
            }
            else{
                l = c;
                left = center;
            }
        }
        if(r - l <= 1) return 0;
    }
}