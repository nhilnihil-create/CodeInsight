#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> num(5, 0);
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        num[a]++;
        num[b]++;
    }

    int num1 = 0, num2 = 0;
    for(int i = 1; i <= 4; i++){
        if(num[i] == 1) num1++;
        else if(num[i] == 2) num2++;
    }

    if(num1 == 2 && num2 == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}